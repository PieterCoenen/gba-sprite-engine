//
// Created by Pieter Coenen on 6/07/2021.
//

#include "HouseScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

HouseScene::HouseScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine){}

std::vector<Background *> HouseScene::backgrounds() {
    return {};
}

std::vector<Sprite *> HouseScene::sprites() {
    return {};
}

void HouseScene::load() {


}

void HouseScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    }else if(keys & KEY_LEFT) {

    }else if(keys & KEY_A) {

    }
}
