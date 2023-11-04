//
// Created by corigan01 on 11/3/23.
//

#include "UI.h"

void UI::add_element(UIElement *element) {
    m_elements.push_back(element);
}

void UI::update_event() {}

void UI::init_all() {
    for (auto &element : m_elements) {
        element->init();
    }
}

void UI::draw2D_all() {
    update_event();
    for (auto &element : m_elements) {
        element->draw2D();
    }
}

void UI::updateUI() {
    for (auto &element : m_elements) {
        element->update();
    }

    Vector2 mouse_pos = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        for (auto &element : m_elements) {
            element->mouse_click(mouse_pos, UIElement::MouseEventType::MOUSE_CLICK_RIGHT);
        }
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (auto &element : m_elements) {
            element->mouse_click(mouse_pos, UIElement::MouseEventType::MOUSE_CLICK_LEFT);
        }
    }
}