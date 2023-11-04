//
// Created by corigan01 on 11/3/23.
//

#pragma once

#include "UIElement.h"

class SimpleElement : public UIElement {
private:
    bool m_mouse_clicked_flag { false };

public:
    SimpleElement() = default;
    ~SimpleElement() = default;

    void init() override;
    void draw2D() override;
    void mouse_click(Vector2 pos, MouseEventType button) override;
};