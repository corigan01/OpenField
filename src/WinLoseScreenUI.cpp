//
// Created by corigan01 on 11/4/23.
//

#include "WinLoseScreenUI.h"

WinLoseScreenUI::WinLoseScreenUI(bool did_win) :
        message { did_win ? "You WON!" : "You Lose!", 300, 100, 25, GREEN } {

    add_element(&message);
}

const char* WinLoseScreenUI::finished_event_control() {
    return nullptr;
}