//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UI.h>
#include <SimpleUIElement.h>

class SimpleStartScreenUI : public UI {
private:
    SimpleElement m_simple {};
public:
    SimpleStartScreenUI();
    ~SimpleStartScreenUI() = default;

    const char* finished_event_control();
};



