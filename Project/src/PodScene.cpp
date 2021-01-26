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
    return {avatar.get(), keyCard.get(), decoy1.get(), decoy2.get(), decoy3.get(), door.get()};
}

void PodScene::load() {
    engine.get()->enableText();

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Space1Pal, sizeof(Space1Pal)));

    SpriteBuilder<Sprite> builder;

    if (color == "white"){
        avatar = builder
                .withData(NASA_Astronaut_WhiteTiles, sizeof(NASA_Astronaut_WhiteTiles))
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .withinBounds()
                .buildPtr();
    } else if (color == "blue"){
        avatar = builder
                .withData(NASA_Astronaut_BlueTiles, sizeof(NASA_Astronaut_BlueTiles))
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .withinBounds()
                .buildPtr();
    } else if (color == "green"){
        avatar = builder
                .withData(NASA_Astronaut_GreenTiles, sizeof(NASA_Astronaut_GreenTiles))
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .withinBounds()
                .buildPtr();
    } else if (color == "purple"){
        avatar = builder
                .withData(NASA_Astronaut_PurpleTiles, sizeof(NASA_Astronaut_PurpleTiles))
                //.withAnimated(12, 3)
                .withLocation(50, 50)
                .withinBounds()
                .buildPtr();
    } else if (color == "red"){
        avatar = builder
                .withData(NASA_Astronaut_RedTiles, sizeof(NASA_Astronaut_RedTiles))
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .withinBounds()
                .buildPtr();
    } else{
        avatar = builder
                .withData(NASA_Astronaut_YellowTiles, sizeof(NASA_Astronaut_YellowTiles))
                .withAnimated(12, 3)
                .withLocation(50, 50)
                .withinBounds()
                .buildPtr();
    }

    keyCard = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(50,10)
            .withinBounds()
            .buildPtr();

    decoy1 = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(200,10)
            .withinBounds()
            .buildPtr();

    decoy2 = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(10,120)
            .withinBounds()
            .buildPtr();

    decoy3 = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(200,120)
            .withinBounds()
            .buildPtr();

    door = builder
            .withData(ballTiles, sizeof(ballTiles))
            .withLocation(10,0)
            .withinBounds()
            .buildPtr();

    bg = std::unique_ptr<Background>(new Background(1, Space1Tiles, sizeof(Space1Tiles), Space1Map, sizeof(Space1Map)));
    bg.get()->useMapScreenBlock(16);
}

void PodScene::tick(u16 keys) {

    Crewmate crewmate;

    int xPos = avatar->getX();
    int yPos = avatar->getY();

    if(keys & KEY_RIGHT) {
        avatar->flipHorizontally(false);
        avatar->moveTo(xPos+1,yPos);
    } else if(keys & KEY_LEFT) {
        avatar->flipHorizontally(true);
        avatar->moveTo(xPos-1,yPos);
    } else if(keys & KEY_UP) {
        avatar->flipVertically(true);
        avatar->moveTo(xPos,yPos-1);
    } else if(keys & KEY_DOWN) {
        avatar->flipVertically(false);
        avatar->moveTo(xPos,yPos+1);
    } else if(keys & KEY_A) {
        if (avatar->collidesWith(*keyCard)){
            TextStream::instance().setText(std::string("You found the key card!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
            crewmate.items.push_back("keyCard");
        }else if (avatar->collidesWith(*decoy1)){
            TextStream::instance().setText(std::string("Too bad this was a dummy!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
        }else if (avatar->collidesWith(*decoy3)){
            TextStream::instance().setText(std::string("Too bad this was a dummy!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
        }else if (avatar->collidesWith(*decoy2)){
            TextStream::instance().setText(std::string("Too bad this was a dummy!") , 5, 10);
            sleep(5);
            TextStream::instance().clear();
        }else if (avatar->collidesWith(*door)){
            if (crewmate.useItem("keyCard")){
                TextStream::instance().setText(std::string("You will now go to the next room") , 5, 10);
                sleep(3);
                engine.get()->setScene(new ControlRoomScene(engine, color));
            }
        }
    }
}