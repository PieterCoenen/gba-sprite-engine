//
// Created by Pieter Coenen on 6/07/2021.
//

#include "InventoryScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

InventoryScene::InventoryScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine){}

std::vector<Background *> InventoryScene::backgrounds() {
    return {};
}

std::vector<Sprite *> InventoryScene::sprites() {
    return {};
}

void InventoryScene::load() {


}

void InventoryScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    }else if(keys & KEY_LEFT) {

    }else if(keys & KEY_A) {

    }
}