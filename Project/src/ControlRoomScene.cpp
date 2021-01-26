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
#include "NASA_Astronaut_White.h"
#include "NASA_Astronaut_Blue.h"
#include "NASA_Astronaut_Green.h"
#include "NASA_Astronaut_Purple.h"
#include "NASA_Astronaut_Red.h"
#include "NASA_Astronaut_Yellow.h"
#include "Space1.h"

std::vector<Background *> ControlRoomScene::backgrounds() {
    return {bg.get()};
}

std::vector<Sprite *> ControlRoomScene::sprites() {
    return { avatar.get()};
}

void ControlRoomScene::load() {
    engine.get()->enableText();

    SpriteBuilder<Sprite> builder;

    if (color == "white"){
        avatar = builder
                .withData(NASA_Astronaut_WhiteTiles, sizeof(NASA_Astronaut_WhiteTiles))
                .withSize(SIZE_16_16)
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .buildPtr();
    } else if (color == "blue"){
        avatar = builder
                .withData(NASA_Astronaut_BlueTiles, sizeof(NASA_Astronaut_BlueTiles))
                .withSize(SIZE_16_16)
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .buildPtr();
    } else if (color == "green"){
        avatar = builder
                .withData(NASA_Astronaut_GreenTiles, sizeof(NASA_Astronaut_GreenTiles))
                .withSize(SIZE_16_16)
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .buildPtr();
    } else if (color == "purple"){
        avatar = builder
                .withData(NASA_Astronaut_PurpleTiles, sizeof(NASA_Astronaut_PurpleTiles))
                .withSize(SIZE_16_16)
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .buildPtr();
    } else if (color == "red"){
        avatar = builder
                .withData(NASA_Astronaut_RedTiles, sizeof(NASA_Astronaut_RedTiles))
                .withSize(SIZE_16_16)
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .buildPtr();
    } else{
        avatar = builder
                .withData(NASA_Astronaut_YellowTiles, sizeof(NASA_Astronaut_YellowTiles))
                .withSize(SIZE_16_16)
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .buildPtr();
    }

    bg = std::unique_ptr<Background>(new Background(1, Space1Tiles, sizeof(Space1Tiles), Space1Map, sizeof(Space1Map)));
    bg.get()->useMapScreenBlock(16);
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