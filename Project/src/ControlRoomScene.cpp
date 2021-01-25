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
    return { avatar.get()};
}

void ControlRoomScene::load() {
    engine.get()->enableText();

    SpriteBuilder<Sprite> builder;

    avatar = builder
            //.withData()
            .withSize(SIZE_16_16)
            .withLocation(50, 50)
            .buildPtr();
}

void ControlRoomScene::tick(u16 keys) {

    if(keys & KEY_RIGHT) {
        avatar->flipHorizontally(false);
    } else if(keys & KEY_LEFT) {
        avatar->flipHorizontally(true);
    } else if(keys & KEY_UP) {
        avatar->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        avatar->flipVertically(false);
    } else if(keys & KEY_A) {
        /*if (avatar->collidesWith(*)){

        }*/
    } else if(keys & KEY_B) {

    }
}