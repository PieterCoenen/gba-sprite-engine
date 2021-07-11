//
// Created by Pieter Coenen on 6/07/2021.
//

#include "HouseScene.h"
#include "InventoryScene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

HouseScene::HouseScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine){}

std::vector<Background *> HouseScene::backgrounds() {
    return {bg.get()};
}

std::vector<Sprite *> HouseScene::sprites() {
    return {avatar.get()};
}

void HouseScene::load() {
    engine.get()->enableText();

}

void HouseScene::tick(u16 keys) {
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
    }else if(keys & KEY_A) {

    }else if(keys & KEY_START){
        engine->setScene(new InventoryScene(engine, "start"));
    }
}
