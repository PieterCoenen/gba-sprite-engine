//
// Created by Pieter Coenen on 11/01/2021.
//

#include "ControlRoomScene.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
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

    bg = std::unique_ptr<Background>(new Background(1, Space1Tiles, sizeof(Space1Tiles), Space1Map, sizeof(Space1Map)));
    bg.get()->useMapScreenBlock(16);
}

void ControlRoomScene::tick(u16 keys) {

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
        TextStream::instance().setText(std::string("Finished so far!") , 5, 3);
    }
}