//
// Created by Pieter Coenen on 10/01/2021.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "PodScene.h"

std::vector<Background *> PodScene::backgrounds() {
    return {};
}

std::vector<Sprite *> PodScene::sprites() {
    return {};
}

void PodScene::load() {
    engine.get()->enableText();
}

void PodScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    } else if(keys & KEY_LEFT) {

    } else if(keys & KEY_UP) {

    } else if(keys & KEY_DOWN) {

    } else if(keys & KEY_B) {

    } else if(keys & KEY_B) {

    }
}