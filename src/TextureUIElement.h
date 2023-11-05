//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UIElement.h>

class TextureUIElement : public UIElement {
private:
    Texture2D texture {};
    Rectangle src {}, target {};
    Vector2 org {};
    float rotation = 0;
    Color tint = WHITE;

    void generate_def();
public:
    explicit TextureUIElement(Rectangle drawing_pos);
    TextureUIElement(const char* filename, Rectangle drawing_pos);
    ~TextureUIElement() = default;

    void draw2D() override;
    void change_rotation(float rot);
    void change_target(Rectangle trg);
    float get_rotation();
    Rectangle get_target();
    Vector2 get_origin();
    void set_origin(Vector2 origin);
    Rectangle get_src();
    void set_src(Rectangle source);
};



