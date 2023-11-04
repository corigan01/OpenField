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

    void generate_def() {
        Image def = GenImageChecked(target.width, target.height, 10, 10, MAGENTA, BLACK);
        texture = LoadTextureFromImage(def);
        UnloadImage(def);
        org = { 0, 0};
    }

public:
    explicit TextureUIElement(Rectangle drawing_pos) {
        src = {0, 0, drawing_pos.width, drawing_pos.height};
        target = drawing_pos;
        generate_def();
    }

    TextureUIElement(const char* filename, Rectangle drawing_pos) {
        Image def = LoadImage(filename);
        texture = LoadTextureFromImage(def);
        org = {0, 0};
        src = {0, 0, static_cast<float>(def.width), static_cast<float>(def.height)};
    }

    ~TextureUIElement() = default;

    void draw2D() override {
        DrawTexturePro(texture, src, target, org, rotation, tint);
    }

    void change_rotation(float rot) {
        this->rotation = rot;
    }

    void change_target(Rectangle trg) {
        this->target = trg;
    }

    float get_rotation() {
        return rotation;
    }

    Rectangle get_target() {
        return target;
    }

    Vector2 get_origin() {
        return org;
    }

    void set_origin(Vector2 origin) {
        org = origin;
    }

    Rectangle get_src() {
        return src;
    }

    void set_src(Rectangle source) {
        src = source;
    }
};



