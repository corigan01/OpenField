//
// Created by corigan01 on 11/4/23.
//

#include "TitleScreenUI.h"

TitleScreenUI::TitleScreenUI() :
        mainTitle { "OpenField", 300, 100, 45, BLACK },
        playGame { 300, 300, 200, 100 },
        background { "../textures/holy.png", {0, 0, 800 * 2, 800 * 2} } {

    background.change_target({800 / 2, 800 / 2, 800 * 2, 800 * 2});
    background.set_origin({800, 800});

    this->add_element(&background);
    this->add_element(&playGame);
    this->add_element(&mainTitle);
}

void TitleScreenUI::update_event() {
    float rot = this->background.get_rotation();
    this->background.change_rotation(rot + 0.05);

    if (playGame.is_clicked()) {
        next_stage = "play";
    }
}

const char* TitleScreenUI::finished_event_control() {
    return next_stage;
}