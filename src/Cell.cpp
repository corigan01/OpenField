//
// Camden did this 11/3/2023
//

#include "Cell.h"

Cell::Cell(int xLocation, int yLocation) {
    x = xLocation;
    y = yLocation;
}


int Cell::what_to_draw() {
    if (isClicked) {
        if (isMine) {
            return -1;
        }
        else {
            return numMines;
        }
    }
    else if (isFlagged) {
        return -2;
    }
    else {
        return -1;
    }
}

// -1 clicked mine, 0 nothing happened, 1 clicked clear space
int Cell::mouse_click(int button) {
    if (isClicked) {
        return 0;
    }
    else if (button == 0) {
        isClicked = true;
        if (isMine) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else if (button == 1) {
        isFlagged = !isFlagged;
        return 0;
    }
    else {
        return 0;
    }
}