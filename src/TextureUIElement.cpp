//
// Created by corigan01 on 11/4/23.
//

#include "TextureUIElement.h"

void TextureUIElement::generate_def() {
    Image def = GenImageChecked(target.width, target.height, 10, 10, MAGENTA, BLACK);
    texture = LoadTextureFromImage(def);
    UnloadImage(def);
    org = { 0, 0};
}

TextureUIElement::TextureUIElement(Rectangle drawing_pos) {
    src = {0, 0, drawing_pos.width, drawing_pos.height};
    target = drawing_pos;
    generate_def();
}

TextureUIElement::TextureUIElement(const char* filename, Rectangle drawing_pos) {
    Image def = LoadImage(filename);
    texture = LoadTextureFromImage(def);
    org = {0, 0};
    src = {0, 0, static_cast<float>(def.width), static_cast<float>(def.height)};
}

void TextureUIElement::draw2D() {
    DrawTexturePro(texture, src, target, org, rotation, tint);
}

void TextureUIElement::change_rotation(float rot) {
    this->rotation = rot;
}

void TextureUIElement::change_target(Rectangle trg) {
    this->target = trg;
}

float TextureUIElement::get_rotation() {
    return rotation;
}

Rectangle TextureUIElement::get_target() {
    return target;
}

Vector2 TextureUIElement::get_origin() {
    return org;
}

void TextureUIElement::set_origin(Vector2 origin) {
    org = origin;
}

Rectangle TextureUIElement::get_src() {
    return src;
}

void TextureUIElement::set_src(Rectangle source) {
    src = source;
}