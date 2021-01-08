//
// Created by Wouter Groeneveld on 29/11/18.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "SplashScreen.h"

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


}

void SplashScreen::load() {

}
