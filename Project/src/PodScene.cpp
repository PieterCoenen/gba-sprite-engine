//
// Created by Pieter Coenen on 10/01/2021.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <unistd.h>
#include "PodScene.h"
#include "SpriteData.h"
#include "crewmate.h"
#include "ControlRoomScene.h"
#include "NASA_Astronaut_White.h"
#include "NASA_Astronaut_Blue.h"
#include "NASA_Astronaut_Green.h"
#include "NASA_Astronaut_Purple.h"
#include "NASA_Astronaut_Red.h"
#include "NASA_Astronaut_Yellow.h"
#include "Space1.h"

std::vector<Background *> PodScene::backgrounds() {
    return {
        bg.get()
    };
}

std::vector<Sprite *> PodScene::sprites() {
    return {avatar.get(), keyCard.get()};
}

void PodScene::load() {
    engine.get()->enableText();

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Space1Pal, sizeof(Space1Pal)));

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

    door = builder
            //.withData(ballTiles, sizeof(ballTiles)) needs to be made
            .withLocation(10,0)
            .buildPtr();

    bg = std::unique_ptr<Background>(new Background(1, Space1Tiles, sizeof(Space1Tiles), Space1Map, sizeof(Space1Map)));
    bg.get()->useMapScreenBlock(16);
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
        if (avatar->collidesWith(*keyCard)){
            TextStream::instance().setText(std::string("You found the key card!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
            crewmate.items.push_back("keyCard");
        }else if (avatar->collidesWith(*decoy)){
            TextStream::instance().setText(std::string("Too bad this was a dummy!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
        }else if (avatar->collidesWith(*door)){
            if (crewmate.useItem("keyCard")){
                TextStream::instance().setText(std::string("You will now go to the next room") , 5, 10);
                sleep(3);
                engine.get()->setScene(new ControlRoomScene(engine, color));
            }
        }else{
            TextStream::instance().setText(std::string("No interaction possible!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
        }
    }
}