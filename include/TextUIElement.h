//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include "UIElement.h"

class TextUIElement : public UIElement {
private:
    const char* text_data = "NO DATA";
    int font = 12;
    int x, y = 0;
    Color text_color = BLACK;

public:
    TextUIElement(const char* text, int x, int y, int font_size, Color color);
    void draw2D() override;
};


