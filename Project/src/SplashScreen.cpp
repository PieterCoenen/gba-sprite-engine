#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "SplashScreen.h"
#include "PodScene.h"
#include "StartScene.h"

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
        engine->setScene(new StartScene(engine));
    }
}

void SplashScreen::load() {
    engine.get()->disableText();



    bg.get()->useMapScreenBlock(24);
}
