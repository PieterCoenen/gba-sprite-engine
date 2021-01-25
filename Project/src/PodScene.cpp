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
    return { avatar.get(), keyCard.get()};
}

void PodScene::load() {
    engine.get()->enableText();

    SpriteBuilder<Sprite> builder;

    avatar = builder
            //.withData()
            .withSize(SIZE_16_16)
            .withLocation(50, 50)
            .buildPtr();

    keyCard = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(10,10)
            .buildPtr();

    decoy = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(230,10)
            .buildPtr();
    decoy = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(10,150)
            .buildPtr();
    decoy = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(230,150)
            .buildPtr();
}

void PodScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {
        avatar->flipHorizontally(false);
    } else if(keys & KEY_LEFT) {
        avatar->flipHorizontally(true);
    } else if(keys & KEY_UP) {
        avatar->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        avatar->flipVertically(false);
    } else if(keys & KEY_A) {
        if (avatar->collidesWith(*keyCard)){
            TextStream::instance().setText(std::string("You found the key card!") , 5, 10);
            TextStream::instance().clear();
        }else if (avatar->collidesWith(*decoy)){
            TextStream::instance().setText(std::string("Too bad this was a dummy!") , 5, 10);
            TextStream::instance().clear();
        }else{
            TextStream::instance().setText(std::string("No interactable item found!") , 5, 10);
            TextStream::instance().clear();
        }
    } else if(keys & KEY_B) {

    }
}