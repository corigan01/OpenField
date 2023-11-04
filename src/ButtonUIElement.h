//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UIElement.h>

class ButtonUIElement : public UIElement {
private:
    int x, y = 0;
    int width, height = 0;

    bool had_been_clicked { false };

public:
    ButtonUIElement(int x, int y, int width, int height);
    ~ButtonUIElement() = default;

    void init() override;
    void draw2D() override;
    void mouse_click(Vector2 pos, MouseEventType button) override;
    bool is_clicked();
};



