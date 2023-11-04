//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <GameField.h>

class MineFieldLogic {
public:
    enum class CurrentGameState {
        GAME_IN_PROGRESS,
        GAME_LOST,
        GAME_WON,
    };

private:
    GameField field;


public:

    MineFieldLogic() :
        field {} {

    }

    MineFieldLogic(int x, int y, int z) :
            field {x, y, z} {

    }

    MineFieldLogic(int x, int y) :
        MineFieldLogic {x, y, 1} {}



};



