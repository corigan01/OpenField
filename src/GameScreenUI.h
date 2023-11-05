//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UI.h>
#include <MineFieldLogic.h>
#include <GameField.h>
#include <ButtonUIElement.h>
#include <IncludeDataWithUIElement.h>

class GameScreenUI : public UI {
private:
    MineFieldLogic logic;
    vector<IncludeDataWithUIElement<MineFieldLogic::CellPos, ButtonUIElement>> buttons;
public:
    GameScreenUI();
    ~GameScreenUI() = default;
    void update_event() override;
    const char* finished_event_control();
};



