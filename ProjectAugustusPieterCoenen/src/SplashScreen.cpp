//
// Created by Pieter Coenen on 3/07/2021.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include "SplashScreen.h"
#include "StartScreen.h"

SplashScreen::SplashScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> SplashScreen::sprites() {
    return {};
}

std::vector<Background *> SplashScreen::backgrounds() {
    return {
            bg.get()
    };
}

void SplashScreen::tick(u16 keys) {
    if(keys & KEY_ANY) {
        engine->setScene(new StartScreen(engine));
    }
}

void SplashScreen::load() {
    engine.get()->disableText();

    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Space1Pal, sizeof(Space1Pal)));

   // bg = std::unique_ptr<Background>(new Background(1, Space1Tiles, sizeof(Space1Tiles), Space1Map, sizeof(Space1Map)));
    bg.get()->useMapScreenBlock(24);
}