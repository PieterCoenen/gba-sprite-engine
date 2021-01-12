//
// Created by Pieter Coenen on 10/01/2021.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "PodScene.h"
#include "SpriteData.h"
#include "crewmate.h"

std::vector<Background *> PodScene::backgrounds() {
    return {};
}

std::vector<Sprite *> PodScene::sprites() {
    return { avatar.get()};
}

void PodScene::load() {
    engine.get()->enableText();

    SpriteBuilder<Sprite> builder;

    avatar = builder
            //.withData()
            .withSize(SIZE_16_16)
            .withLocation(50, 50)
            .buildPtr();

    auto keyCard = builder
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(10,10) //location is now just a random value
            .buildPtr();
    auto dummy1 = builder
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(230,10) //location is now just a random value
            .buildPtr();
    auto dummy2 = builder
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(10,150) //location is now just a random value
            .buildPtr();
    auto dummy3 = builder
            .withData(ballTiles, sizeof(ballTiles)) //needs to be tested to see if this is the right sprite
            .withLocation(230,150) //location is now just a random value
            .buildPtr();
}

void PodScene::tick(u16 keys) {
    Crewmate crewmate;

    if(keys & KEY_RIGHT) {
        avatar->flipHorizontally(false);
    } else if(keys & KEY_LEFT) {
        avatar->flipHorizontally(true);
    } else if(keys & KEY_UP) {
        avatar->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        avatar->flipVertically(false);
    } else if(keys & KEY_A) {
        if (crewmate.interactableItem()){
            crewmate.interact();
        }
    } else if(keys & KEY_B) {

    }
}