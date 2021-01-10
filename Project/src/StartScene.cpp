//
// Created by Pieter Coenen on 10/01/2021.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "StartScene.h"
#include "pod_scene.h"

StartScene::StartScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine), color("red") {}

std::vector<Background *> StartScene::backgrounds() {
    return {};
}

std::vector<Sprite *> StartScene::sprites() {
    return {};
}

void StartScene::load() {

}

void StartScene::tick(u16 keys) {

}