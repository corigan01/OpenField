//
// Camden did this 11/4/2023
//

#pragma once
#include <vector>
#include "UIElement.h"
#include "Cell.h"

class Field2D : public UIElement {
private:
    std::vector<std::vector<Cell>>field;
    const int cellWidth = 25;
    const int cellHeight = 25;

public:
    Field2D(int rows, int columns, int mines);
    ~Field2D() = default;


    void init() override;
    void draw2D() override;
    void mouse_click(Vector2 pos, MoueClickButton button) override;
};