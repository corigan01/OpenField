//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UI.h>

class GameScreenUI : public UI {
private:

public:
    GameScreenUI() {

    }

    ~GameScreenUI() = default;

    const char* finished_event_control() {
        return nullptr;
    }
};



