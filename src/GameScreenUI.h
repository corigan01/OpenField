//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UI.h>
#include <Field2D.h>

class GameScreenUI : public UI {
private:
    Field2D field;

public:
    GameScreenUI() :
            field {10, 10, 10} {

        this->add_element(&field);
    }

    ~GameScreenUI() = default;

    const char* finished_event_control() {
        return nullptr;
    }
};



