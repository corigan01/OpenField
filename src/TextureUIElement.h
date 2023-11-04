//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UIElement.h>

class TextureUIElement : public UIElement {
private:
    Texture2D texture;
    Rectangle src, target = {};
    Vector2 org = {};
    float rotation = 0;
    Color tint = WHITE;

    void generate_def() {
        Image def = GenImageChecked(target.width, target.height, 10, 10, MAGENTA, BLACK);
        texture = LoadTextureFromImage(def);
        UnloadImage(def);
        org = { target.width / 2, target.height / 2};
    }

public:
    TextureUIElement(Rectangle drawing_pos) {
        target = drawing_pos;
        src = drawing_pos;
        generate_def();
    }

    ~TextureUIElement() = default;

    void draw2D() override {
        DrawTexturePro(texture, src, target, org, rotation, tint);
    }

};



