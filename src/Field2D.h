//
// Camden did this 11/4/2023
//

#pragma once
#include <vector>
#include <UIElement.h>
#include <Cell.h>

class Field2D : public UIElement {
private:
    std::vector<std::vector<Cell>>field;
    const int cell_width = 25;
    const int cell_height = 25;
    const int start_x = 25;
    const int start_y = 25;
    const int font_size = 25;
    int rows;
    int columns;
    int mines;
    int spaces_remaining;

public:
    Field2D(int rows, int columns, int mines);
    ~Field2D() = default;

    void add_mines();
    void count_mines();
    void count_around(int row, int column);
    void clear_around(int row, int column);

    void init() override;
    void draw2D() override;
    void mouse_click(Vector2 pos, MouseEventType button) override;
};