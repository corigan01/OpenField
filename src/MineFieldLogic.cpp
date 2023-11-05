//
// Created by corigan01 on 11/4/23.
//

#include "MineFieldLogic.h"
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

#define FOR_EACH_ELEMENT_IN_FIELD(stuff_to_do)      \
    for (int x = 0; x < m_field.x(); x++) {         \
        for (int y = 0; y < m_field.y(); y++) {     \
            for (int z = 0; z < m_field.z(); z++) { \
                stuff_to_do                         \
            }                                       \
        }                                           \
    }

#define FOR_EACH_ELEMENT_3X3X3_AROUND(pos_x, pos_y, pos_z, stuff_to_do)                                     \
    for (int x = SIMPLE_MAX((pos_x) - 1, 0); x < SIMPLE_MIN((pos_x) + 2, m_field.x()); x++) {               \
        for (int y = SIMPLE_MAX((pos_y) - 1, 0); y < SIMPLE_MIN((pos_y) + 2, m_field.y()); y++) {           \
            for (int z = SIMPLE_MAX((pos_z) - 1, 0); z < SIMPLE_MIN((pos_z) + 2, m_field.z()); z++) {       \
                stuff_to_do                                                                                 \
            }                                                                                               \
        }                                                                                                   \
    }


MineFieldLogic::CellPos MineFieldLogic::pick_random_cell() {
    int rng_x = rand() % m_field.x();
    int rng_y = rand() % m_field.y();
    int rng_z = rand() % m_field.z();

    return {rng_x, rng_y, rng_z};
}

int MineFieldLogic::mines_around_cell(int pos_x, int pos_y, int pos_z) {
    int mines = 0;

    FOR_EACH_ELEMENT_3X3X3_AROUND(pos_x, pos_y, pos_z,
                                  if (x == pos_x && y == pos_y && z == pos_z) {
                                      continue;
                                  }

                                          GameField::Cell* cell = m_field.get_cell(x, y, z);
                                          if (IS_MINE_CELL(cell)) {
                                              mines++;
                                          }
    )

    return mines;
}

void MineFieldLogic::check_for_finished() {
    if (mines_flagged != mines_on_field) {
        return;
    }

    FOR_EACH_ELEMENT_IN_FIELD(
            GameField::Cell* cell = m_field.get_cell(x, y, z);

            if (IS_MINE_CELL(cell) && !cell->is_flagged) return;
    )

    state = CurrentGameState::GAME_WON;
}


MineFieldLogic::MineFieldLogic() :
        m_field {} {
    srand(time(nullptr));
}

MineFieldLogic::MineFieldLogic(int x, int y, int z) :
        m_field {x, y, z} {
    srand(time(nullptr));
}

MineFieldLogic::MineFieldLogic(int x, int y) :
        MineFieldLogic {x, y, 1} {}

MineFieldLogic::CurrentGameState MineFieldLogic::get_game_state() {
    return state;
}

void MineFieldLogic::reset_game() {
    m_field.reset();
    state = CurrentGameState::GAME_IN_PROGRESS;
    mines_flagged = 0;
    mines_on_field = 0;
}

void MineFieldLogic::distribute_mines(int mines_count) {
    mines_count = SIMPLE_MIN(mines_count, m_field.x() * m_field.y() * m_field.z());
    mines_on_field = mines_count;

    while(mines_count > 0) {
        CellPos pos = pick_random_cell();
        GameField::Cell* cell = m_field.get_cell(pos.x, pos.y, pos.z);

        if (IS_MINE_CELL(cell)) {
            continue;
        }

        mines_count--;
        cell->state = GameField::MineState::CONTAINS_MINE;
    }
}

void MineFieldLogic::populate_numbers() {
    FOR_EACH_ELEMENT_IN_FIELD(
            GameField::Cell* cell = m_field.get_cell(x, y, z);

            if (!IS_EMPTY_CELL(cell)) {
                continue;
            }

            cell->state = INT_TO_MINE_STATE(mines_around_cell(x, y, z));
    )
}

void MineFieldLogic::register_rec(CellPos pos) {
    if (pos.x >= m_field.x() || pos.y >= m_field.y() || pos.z >= m_field.z() || pos.x < 0 || pos.y < 0 || pos.z < 0) {
        return;
    }

    GameField::Cell* cell = m_field.get_cell(pos.x, pos.y, pos.z);

    if (!cell->is_hidden) {
        return;
    }

    if (IS_EMPTY_CELL(cell) || IS_NUMBER_CELL(cell)) {
        cell->is_hidden = false;
    }

    if (IS_EMPTY_CELL(cell)) {
        // Please for the FUCKING LOVE OF GOD REMOVE THIS HELL
        register_rec({pos.x + 1, pos.y, pos.z});
        register_rec({pos.x - 1, pos.y, pos.z});
        register_rec({pos.x, pos.y + 1, pos.z});
        register_rec({pos.x, pos.y - 1, pos.z});
        register_rec({pos.x, pos.y, pos.z + 1});
        register_rec({pos.x, pos.y, pos.z - 1});
    }
}

void MineFieldLogic::register_pick(CellPos pos) {
    if (pos.x >= m_field.x() || pos.y >= m_field.y() || pos.z >= m_field.z() || pos.x < 0 || pos.y < 0 || pos.z < 0) {
        return;
    }

    GameField::Cell* cell = m_field.get_cell(pos.x, pos.y, pos.z);

    if (IS_MINE_CELL(cell)) {
        state = CurrentGameState::GAME_LOST;
    }

    register_rec(pos);
}

void MineFieldLogic::register_flag(CellPos pos) {
    GameField::Cell* cell = m_field.get_cell(pos.x, pos.y, pos.z);
    cell->is_flagged = !cell->is_flagged;
    mines_flagged += cell->is_flagged ? 1 : 0;
    check_for_finished();
}

GameField::Cell* MineFieldLogic::get_cell(CellPos pos) {
    return m_field.get_cell(pos.x, pos.y, pos.z);
}

void MineFieldLogic::debug_print_to_terminal(int z) {
    for (int x = 0; x < m_field.x(); x++) {
        for (int y = 0; y < m_field.y(); y++) {
            GameField::Cell* cell = m_field.get_cell(x, y, z);

            if (cell->is_hidden) {
                cout << "H | ";
                continue;
            }

            if (IS_MINE_CELL(cell)) {
                cout << "X | ";
                continue;
            }

            if (IS_EMPTY_CELL(cell)) {
                cout << "  | ";
                continue;
            }

            cout << cell->state << " | ";
        }
        cout << endl;
    }
}
