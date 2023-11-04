//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UI.h>
#include <TextUIElement.h>
#include <ButtonUIElement.h>
#include <TextureUIElement.h>

class TitleScreenUI : public UI {
private:
    TextUIElement mainTitle;
    ButtonUIElement playGame;
    TextureUIElement background;

    const char* next_stage = nullptr;

public:
    TitleScreenUI();
    ~TitleScreenUI() = default;

    void update_event() override;
    const char* finished_event_control() override;
};


