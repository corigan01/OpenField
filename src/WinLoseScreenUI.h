//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UI.h>
#include <TextUIElement.h>

class WinLoseScreenUI : public UI {
private:
    TextUIElement message;

public:
    WinLoseScreenUI(bool did_win);
    ~WinLoseScreenUI() = default;
    const char* finished_event_control();
};


