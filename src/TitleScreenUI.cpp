//
// Created by corigan01 on 11/4/23.
//

#include <TitleScreenUI.h>

TitleScreenUI::TitleScreenUI() :
        mainTitle { "OpenField", 300, 100, 45, BLACK },
        playGame { 300, 300, 200, 100 } {

    this->add_element(&playGame);
    this->add_element(&mainTitle);
}

void TitleScreenUI::update_event() {
    if (playGame.is_clicked()) {
        next_stage = "play";
    }
}

const char* TitleScreenUI::finished_event_control() {
    return next_stage;
}