//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <cassert>
#include <cstdlib>

#define IS_NUMBER_CELL(cell) ((cell)->state > 0)
#define IS_EMPTY_CELL(cell) ((cell)->state == GameField::MineState::EMPTY_SPACE)
#define IS_MINE_CELL(cell) ((cell)->state == GameField::MineState::CONTAINS_MINE)
#define INT_TO_MINE_STATE(val) ((GameField::MineState)(val))

class GameField {
public:
    enum MineState {
        CONTAINS_MINE = -1,
        EMPTY_SPACE = 0,
    };

    struct Cell {
        MineState state = MineState::EMPTY_SPACE;
        bool is_hidden = true;
        bool is_flagged = false;
    };

private:
    Cell* m_board;
    int size_x = 10, size_y = 10, size_z = 1;
    size_t size_bytes_sanity_check = size_x * size_y * size_z * sizeof(Cell);
public:

    GameField();
    GameField(int x, int y);
    GameField(int x, int y, int z);
    ~GameField();

    void reset();

    [[nodiscard]] Cell* get_cell(int x, int y, int z) const;
    [[nodiscard]] Cell* get_cell(int x, int y) const;

    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;
    [[nodiscard]] int z() const;
};


