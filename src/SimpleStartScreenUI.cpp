//
// Created by corigan01 on 11/4/23.
//

#include "SimpleStartScreenUI.h"

SimpleStartScreenUI::SimpleStartScreenUI() {
    this->add_element(&m_simple);
}

const char* SimpleStartScreenUI::finished_event_control() {
    return (const char*)nullptr;
}