//
// Camden did this 11/4/2023
//
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <Field2D.h>
#include <chrono>

Field2D::Field2D(int rows, int columns, int mines) {
    this->rows = rows;
    this->columns = columns;
    this->mines = mines;
    spaces_remaining = rows * columns;
    // ayo gavin tell me a better way to do this
    for (int i = 0; i < rows; i++) {
        std::vector<Cell> temp;
        for (int j = 0; j < columns; j++) {
            temp.push_back(Cell(start_x + i*cell_width, start_y + j*cell_height));
        }
        field.push_back(temp);
    }

    add_mines();
}

void Field2D::add_mines() {
    srand(std::time(nullptr)); // why is not allowed?
    int random_variable;
    for (int i = 0; i < mines; i++) {
        do {
            random_variable = rand() % (rows * columns);
        } while (field.at(random_variable % rows).at(random_variable / rows).isMine);

        field.at(random_variable % rows).at(random_variable / rows).isMine = true;
        count_around(random_variable % rows, random_variable / rows);
    }
}

void Field2D::count_around(int row, int column) {
    int rows = field.size();
    int columns = field.at(0).size();
    for (int k = (0 > row - 1 ? 0 : row - 1); k < (rows < row + 2 ? rows : row + 2); k++) {
        for (int l = (0 > column - 1 ? 0 : column - 1); l < (columns < column + 2 ? columns : column + 2); l++) {
            field.at(k).at(l).numMines++;
        }
    }
}


//not used right now
void Field2D::count_mines() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (field.at(i).at(j).isMine) {
                for (int k = (0 > i - 1 ? 0 : i - 1); k < (rows < i + 1 ? rows : i + 1); k++) {
                    for (int l = (0 > j - 1 ? 0 : j - 1); l < (columns < j + 1 ? columns : j + 1); l++) {
                        if (!field.at(k).at(l).isMine) {
                            field.at(k).at(l).numMines++;
                        }
                    }
                }
            }
        }
    }
}

void Field2D::init() {
    // nothing right now
}

void Field2D::draw2D() {
    int draw;
    for(int i = 0; i < field.size(); i++) {
        for(int j = 0; j < field.at(i).size(); j++) {
            draw = field.at(i).at(j).what_to_draw();
            if (draw == -3) {
                DrawRectangleLines(start_x + (j*cell_width), start_y + (i*cell_height), cell_width, cell_height, BLACK);
            }
            else if (draw > 0) {
                const char* draw_string = std::to_string(draw).c_str();
                DrawText(draw_string, start_x + (j * cell_width) + ((cell_width - MeasureText(draw_string, font_size)) / 2), start_y + (i * cell_height), font_size,
                         BLACK);
            }
            else if (draw == -2) {
                DrawRectangleLines(start_x + (j*cell_width), start_y + (i*cell_height), cell_width, cell_height, BLACK);
                const char* draw_string = "O";
                DrawText(draw_string, start_x + (j * cell_width) + ((cell_width - MeasureText(draw_string, font_size)) / 2), start_y + (i * cell_height), font_size,
                         BLACK);
            }
            else if (draw == -1) {
                const char* draw_string = "X";
                DrawText(draw_string, start_x + (j * cell_width) + ((cell_width - MeasureText(draw_string, font_size)) / 2), start_y + (i * cell_height), font_size,
                         BLACK);
            }
        }
    }
}

void Field2D::mouse_click(Vector2 pos, MouseEventType button) {
    if (pos.y >= start_y && pos.y <= (start_y + (rows * cell_height)) && pos.x >= start_x && pos.x <= (start_x + (columns * cell_width))) {
        int row = ((int) pos.y - start_y) / cell_height;
        int column = ((int) pos.x - start_x) / cell_width;
        int b = button == UIElement::MouseEventType::MOUSE_CLICK_LEFT ? 0 : 1;
        int click_event = field.at(row).at(column).mouse_click((b));
        if (click_event == 1) {
            spaces_remaining--;
            if (spaces_remaining <= 0) {
                std::cout << "You Win" << std::endl;
            }
            if (field.at(row).at(column).numMines == 0) {
                clear_around(row, column);
            }
        }
        else if (click_event == 2) {
            mines--;
        }
        else if (click_event == 3) {
            mines++;
        }
        else if (click_event == -1) {
            std::cout << "You Lose" << std::endl;
        }
    }
}

void Field2D::clear_around(int row, int column) {
    for (int k = (0 > row - 1 ? 0 : row - 1); k < (rows < row + 2 ? rows : row + 2); k++) {
        for (int l = (0 > column - 1 ? 0 : column - 1); l < (columns < column + 2 ? columns : column + 2); l++) {
            mouse_click(Vector2(start_x + (cell_height * l), start_y + (cell_height * k)), UIElement::MouseEventType::MOUSE_CLICK_LEFT);
        }
    }
}
