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
        UI ui;
        const char* name;
    };

    vector<MenuChunk> m_uis;
    MenuChunk* current_ui;

    MenuChunk* find_menu(const char* name) {
        for (auto& chunk : m_uis) {
            if (chunk.name == name) {
                return &chunk;
            }
        }

        return (MenuChunk*)nullptr;
    }

public:
    void add_menu(const char* menu_name, const UI& element) {
        m_uis.push_back({
            .ui = element,
            .name = menu_name
        });
    }

    int switch_menu(const char* menu_to_start) {
        MenuChunk* menu = find_menu(menu_to_start);
        if (!menu) {
            return -1;
        }

        menu->ui.init_all();
        current_ui = menu;
    }

    void draw2D() {
        if (!current_ui) {
            return;
        }

        current_ui->ui.draw2D_all();
    }

    void update() {
        if (!current_ui) {
            return;
        }

        current_ui->ui.updateUI();
    }
};
