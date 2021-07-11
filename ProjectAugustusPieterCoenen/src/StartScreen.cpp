//
// Created by Pieter Coenen on 3/07/2021.
//

#include "StartScreen.h"
#include "MainScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

StartScreen::StartScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine){}

std::vector<Background *> StartScreen::backgrounds() {
    return {};
}

std::vector<Sprite *> StartScreen::sprites() {
    return {};
}

void StartScreen::load() {
    TextStream::instance().setText(std::string("Controls:"), 1, 1);
    TextStream::instance().setText(std::string("Use arrows to move"), 3, 1);
    TextStream::instance().setText(std::string("Press A to plant/harvest crops"), 4, 1);
    TextStream::instance().setText(std::string("Press START to access the inventory"), 5, 1);
    TextStream::instance().setText(std::string("Press START to start the game!"), 10, 1);
}

void StartScreen::tick(u16 keys) {
    if(keys & KEY_START){
        engine->setScene(new MainScene(engine));
    }
}