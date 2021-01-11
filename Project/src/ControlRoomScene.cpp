//
// Created by Pieter Coenen on 11/01/2021.
//

#include "ControlRoomScene.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "PodScene.h"
#include "SpriteData.h"

std::vector<Background *> ControlRoomScene::backgrounds() {
    return {};
}

std::vector<Sprite *> ControlRoomScene::sprites() {
    return {};
}

void ControlRoomScene::load() {
    engine.get()->enableText();

}

void ControlRoomScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    } else if(keys & KEY_LEFT) {

    } else if(keys & KEY_UP) {

    } else if(keys & KEY_DOWN) {

    } else if(keys & KEY_A) {

    } else if(keys & KEY_B) {

    }
}