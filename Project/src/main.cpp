#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "pod_scene.h"
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
