//
// Created by corigan01 on 11/4/23.
//

#include "ButtonUIElement.h"

ButtonUIElement::ButtonUIElement(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void ButtonUIElement::draw2D() {
    DrawRectangle(x, y, width, height, BLUE);
}

void ButtonUIElement::mouse_click(Vector2 pos, MouseEventType button) {
    if (button != UIElement::MouseEventType::MOUSE_CLICK_LEFT) {
        return;
    }

    had_been_clicked = CheckCollisionPointRec(
        pos,
        {
                static_cast<float>(x),
                static_cast<float>(y),
                static_cast<float>(width),
                static_cast<float>(height)
        });
}

bool ButtonUIElement::is_clicked() {
    bool clicked = had_been_clicked;
    had_been_clicked = false;
    return clicked;
}