//
// Created by corigan01 on 11/4/23.
//

#include "GameScreenUI.h"
#include "MineFieldLogic.h"

GameScreenUI::GameScreenUI() {
    logic.distribute_mines(10);
    logic.populate_numbers();

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int x_pos = x * 12;
            int y_pos = y * 12;

            ButtonUIElement button = {
                    x_pos + 100,
                    y_pos + 100,
                    10,
                    10
            };

            buttons.push_back({{x, y, 0}, button});
        }
    }

    for (auto &button : buttons) {
        this->add_element(&button);
    }
}

void GameScreenUI::update_event() {
    for (auto &button : buttons) {
        if (button.is_clicked()) {
            logic.register_pick(button.data);
        }
    }

    for (auto &button : buttons) {
        GameField::Cell* cell = logic.get_cell(button.data);
        button.set_hidden(cell->is_hidden);
    }
}


const char* GameScreenUI::finished_event_control() {
    MineFieldLogic::CurrentGameState state = logic.get_game_state();
    if (state == MineFieldLogic::CurrentGameState::GAME_WON) {
        return "won";
    }
    if (state == MineFieldLogic::CurrentGameState::GAME_LOST) {
        return "lost";
    }

    return nullptr;
}