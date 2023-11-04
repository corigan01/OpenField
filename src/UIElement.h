//
// Created by corigan01 on 11/3/23.
//

#pragma once

#include "raylib.h"

class UIElement {
public:
    enum class MouseEventType {
        MOUSE_CLICK_LEFT,
        MOUSE_CLICK_RIGHT
    };

    virtual void init() = 0;
    virtual void draw2D() = 0;
    virtual void mouse_click(Vector2 pos, MouseEventType button) = 0;
};


