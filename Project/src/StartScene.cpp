//
// Created by Pieter Coenen on 10/01/2021.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "StartScene.h"
#include "PodScene.h"

int i = 0;

StartScene::StartScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine), color() {}

void StartScene::fillColors() {
    colors.push_back("red");
    colors.push_back("blue");
    colors.push_back("white");
    colors.push_back("green");
    colors.push_back("purple");
    colors.push_back("yellow");
    color = colors[0];
}

std::vector<Background *> StartScene::backgrounds() {
    return {};
}

std::vector<Sprite *> StartScene::sprites() {
    return {};
}

void StartScene::load() {
    fillColors();

    TextStream::instance().setText(std::string("Space disaster"), 1, 1);
    TextStream::instance().setText(std::string("Left/Right to change color"), 10, 1);
    TextStream::instance().setText(std::string("Start to play"), 12, 1);

}

void StartScene::tick(u16 keys) {
    TextStream::instance().setText(std::string("Color: ") + std::string(color), 5, 1);

    if(keys & KEY_START) {
        engine.get()->setScene(new PodScene(engine, color));
    }
    if(keys & KEY_RIGHT) {
        if (0<=i<5){
            i++;
            color = colors[i];
        }
    } else if(keys & KEY_LEFT) {
        if (0>i>=1){
            i--;
            color = colors[i];
        }
    }
}