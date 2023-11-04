//
// Camden did this 11/4/2023
//
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Field2D.h"

Field2D::Field2D(int rows, int columns, int mines) {

    // ayo gavin tell me a better way to do this
    for (int i = 0; i < rows; i++) {
        std::vector<Cell> temp;
        for (int j = 0; j < columns; j++) {
            temp.push_back(Cell(start_x + i*cell_width, start_y + j*cell_height));
        }
        field.push_back(temp);
    }

    srand(std::time(nullptr)); // why is not allowed?
    int random_variable;
    int remainder;
    for (int i = 0; i < mines; i++) {

        do {
            random_variable = rand() % (rows * columns);
        } while (field.at(random_variable % rows).at(random_variable / rows).isMine);

        field.at(random_variable % rows).at(random_variable / rows).isMine = true;
    }

    // GAZE UPON ITS GLORY
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int surrounding_mines = 0;
            for (int k = (0 > i - 1  ? 0 : i - 1); k < (rows < i + 1 ? rows : i + 1); k++) {
                for (int l = (0 > j - 1  ? 0 : j - 1); l < (columns < j + 1 ? columns : j + 1); l++) {
                    if (field.at(k).at(l).isMine && !(k == 0 && l == 0)) {
                        surrounding_mines++;
                    }
                }
            }
            field.at(i).at(j).numMines = surrounding_mines;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << field.at(i).at(j).numMines << " ";
        }
        std::cout << std::endl;
    }


}

void Field2D::init() {
    // Do nothing
}

void Field2D::draw2D() {
    int draw;
    for(std::vector<Cell> v : field) {
        for(Cell c : v) {
            draw = c.what_to_draw();
            // do some drawing
        }
    }
}

void Field2D::mouse_click(Vector2 pos, MoueClickButton button) {
    // find what cell (if any) was clicked on
    // click it
}