//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <vector>
#include <UI.h>

using std::vector;

class MenuMeta {
private:
    struct MenuChunk {
        UI* ui;
        const char* name;
    };

    vector<MenuChunk> m_uis;
    MenuChunk* current_ui;

    MenuChunk* find_menu(const char* name);

public:
    void add_menu(const char* menu_name, UI* element);
    int switch_menu(const char* menu_to_start);
    void draw2D();
    void update();
};
