//
// Created by corigan01 on 11/3/23.
//

#include "UI.h"

void UI::add_element(UIElement *element) {
    m_elements.push_back(element);
}

void UI::init_all() {
    for (auto &element : m_elements) {
        element->init();
    }
}

void UI::draw2D_all() {
    for (auto &element : m_elements) {
        element->draw2D();
    }
}

void UI::updateUI() {
    Vector2 mouse_pos = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        for (auto &element : m_elements) {
            element->mouse_click(mouse_pos, UIElement::MoueClickButton::MOUSE_CLICK_RIGHT);
        }
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (auto &element : m_elements) {
            element->mouse_click(mouse_pos, UIElement::MoueClickButton::MOUSE_CLICK_LEFT);
        }
    }
}