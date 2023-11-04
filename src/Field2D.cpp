//
// Camden did this 11/4/2023
//

#include "Field2D.h"

Field2D::Field2D(int rows, int columns, int mines) {
    field.resize(rows);
    // this is ugly
    for(vector v : field) {
        field.resize(columns);
    }
}

void Field2D::init() {
    // Do nothing
}

void Field2D::draw2D() {
    int draw;
    for(vector v : field) {
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