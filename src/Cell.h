//
// Camden did this 11/3/2023
//

#pragma once

class Cell {
private:
    bool isClicked { false };
    bool isFlagged { false };

public:
    int x;
    int y;
    bool isMine { false };
    int numMines { -1 };
    Cell(int xLocation, int yLocation);
    ~Cell() = default;

    int what_to_draw();
    int mouse_click(int button);
};