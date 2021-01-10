#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "PodScene.h"
#include "SplashScreen.h"

int main(){

    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto scene = new SplashScreen(engine);
    engine->setScene(scene);

    while (true) {
        engine->update();
    }

    return 0;
}

