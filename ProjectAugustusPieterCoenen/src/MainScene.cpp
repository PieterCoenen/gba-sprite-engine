//
// Created by Pieter Coenen on 3/07/2021.
//

#include "MainScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

MainScene::MainScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine){}

std::vector<Background *> MainScene::backgrounds() {
    return {};
}

std::vector<Sprite *> MainScene::sprites() {
    return {};
}

void MainScene::load() {


}

void MainScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    }else if(keys & KEY_LEFT) {

    }else if(keys & KEY_A) {

    }
}