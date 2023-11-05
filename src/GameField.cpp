//
// Created by corigan01 on 11/4/23.
//

#include "GameField.h"

GameField::GameField() {
    m_board = new Cell[size_z * size_y * size_x];
}

GameField::GameField(int x, int y) :
        GameField {x, y, 1} {}

GameField::GameField(int x, int y, int z) {
    size_x = x;
    size_y = y;
    size_z = z;
    size_bytes_sanity_check = size_x * size_y * size_z * sizeof(Cell);
    m_board = new Cell[size_z * size_y * size_x];
}

GameField::~GameField() {
    delete m_board;
}

GameField::Cell* GameField::get_cell(int x, int y, int z) const {
    assert(x < size_x);
    assert(y < size_y);
    assert(z < size_z);

    size_t offset = (x % size_x) + ((y % size_y) * size_x) + ((z % size_z) * (size_x * size_y));
    assert(offset < size_bytes_sanity_check);

    return &m_board[offset];
}

GameField::Cell* GameField::get_cell(int x, int y) const {
    return get_cell(x, y, 1);
}

int GameField::x() const {
    return size_x;
}

int GameField::y() const {
    return size_y;
}

int GameField::z() const {
    return size_z;
}

void GameField::reset() {
    for (size_t cell = 0; cell < (size_x * size_y * size_z); cell++) {
        m_board[cell] = Cell {};
    }
}