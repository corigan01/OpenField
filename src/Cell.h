//
// Camden did this 11/3/2023
//

#pragma once


class Cell {
private:
    bool isClicked { false };
    bool isFlagged { false };
public:
    int numMines{ -1 };
    bool isMine{ false };

    Cell() = default;
    ~Cell() = default;

    void draw2D();
    int mouse_click(MoueClickButton button);
};