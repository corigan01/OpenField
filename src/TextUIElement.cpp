//
// Created by corigan01 on 11/4/23.
//

#include <TextUIElement.h>

TextUIElement::TextUIElement(const char* text, int x, int y, int font_size, Color color) {
    text_data = text;
    this->x = x;
    this->y = y;
    font = font_size;
    text_color = color;
}

void TextUIElement::draw2D() {
    DrawText(text_data, x, y, font, text_color);
}
