//
// Created by corigan01 on 11/3/23.
//

#pragma once

#include <vector>
#include "UIElement.h"

using std::vector;

class UI {
private:
    vector<UIElement*> m_elements;

public:
    UI() = default;
    ~UI() = default;

    // Handle your own control of UI
    virtual const char* finished_event_control() = 0;

    // Add element to the handler of the elements
    void add_element(UIElement *element);

    // init all elements
    void init_all();

    // draw all elements
    void draw2D_all();

    // update the UI class
    void updateUI();
};