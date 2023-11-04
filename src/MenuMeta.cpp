//
// Created by corigan01 on 11/4/23.
//

#include "MenuMeta.h"
#include <cstring>

MenuMeta::MenuChunk* MenuMeta::find_menu(const char* name) {
    for (auto& chunk : m_uis) {
        if (strcmp(chunk.name, name) == 0) {
            return &chunk;
        }
    }

    return (MenuChunk*)nullptr;
}

void MenuMeta::add_menu(const char* menu_name, UI* element) {
    m_uis.push_back({
                            .ui = element,
                            .name = menu_name
                    });
}

int MenuMeta::switch_menu(const char* menu_to_start) {
    MenuChunk* menu = find_menu(menu_to_start);
    if (!menu) {
        return -1;
    }

    SetWindowTitle(menu->name);
    menu->ui->init_all();
    current_ui = menu;
}

void MenuMeta::draw2D() {
    if (!current_ui) {
        return;
    }

    current_ui->ui->draw2D_all();
}

void MenuMeta::update() {
    if (!current_ui) {
        return;
    }

    current_ui->ui->updateUI();

    const char* maybe_next_screen = current_ui->ui->finished_event_control();
    if (!maybe_next_screen) {
        return;
    }

    MenuChunk* maybe_menu = find_menu(maybe_next_screen);
    if (!maybe_menu) {
        return;
    }

    SetWindowTitle(maybe_menu->name);
    current_ui = maybe_menu;
}