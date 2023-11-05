//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <GameField.h>

#define SIMPLE_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define SIMPLE_MIN(x, y) (((x) < (y)) ? (x) : (y))

class MineFieldLogic {
public:
    enum class CurrentGameState {
        GAME_UNKNOWN,
        GAME_IN_PROGRESS,
        GAME_LOST,
        GAME_WON,
    };

    struct CellPos {
        int x = 0, y = 0, z = 0;
    };

private:
    GameField m_field;
    CurrentGameState state = CurrentGameState::GAME_UNKNOWN;

    int mines_on_field = 0;
    int mines_flagged = 0;

    CellPos pick_random_cell();
    int mines_around_cell(int pos_x, int pos_y, int pos_z);
    void check_for_finished();

public:
    MineFieldLogic();
    MineFieldLogic(int x, int y, int z);
    MineFieldLogic(int x, int y);

    int get_flags();
    CellPos get_field_size();

    void reset_game();
    void distribute_mines(int mines_count = 10);
    void populate_numbers();
    void register_rec(CellPos pos);
    void register_pick(CellPos pos);
    void register_flag(CellPos pos);
    GameField::Cell* get_cell(CellPos pos);
    void debug_print_to_terminal(int z = 0);
    CurrentGameState get_game_state();
};



