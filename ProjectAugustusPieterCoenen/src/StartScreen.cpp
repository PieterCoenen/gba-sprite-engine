//
// Created by Pieter Coenen on 3/07/2021.
//

#include "StartScreen.h"
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


}

void StartScreen::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    }else if(keys & KEY_LEFT) {

    }else if(keys & KEY_A) {

    }
}