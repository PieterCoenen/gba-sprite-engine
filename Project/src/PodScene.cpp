//
// Created by Pieter Coenen on 10/01/2021.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "PodScene.h"
#include "SpriteData.h"

std::vector<Background *> PodScene::backgrounds() {
    return {};
}

std::vector<Sprite *> PodScene::sprites() {
    return {};
}

void PodScene::load() {
    engine.get()->enableText();

    auto keyCard = SpriteBuilder<Sprite>()
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(10,10) //location is now just a random value
            .buildPtr();
    auto dummy1 = SpriteBuilder<Sprite>()
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(20,20) //location is now just a random value
            .buildPtr();
    auto dummy2 = SpriteBuilder<Sprite>()
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(10,20) //location is now just a random value
            .buildPtr();
    auto dummy3 = SpriteBuilder<Sprite>()
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(20,10) //location is now just a random value
            .buildPtr();
}

void PodScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {

    } else if(keys & KEY_LEFT) {

    } else if(keys & KEY_UP) {

    } else if(keys & KEY_DOWN) {

    } else if(keys & KEY_A) {

    } else if(keys & KEY_B) {

    }
}