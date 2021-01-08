#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "sample_start_scene.h"

std::vector<Background *> SampleStartScene::backgrounds() {
    return {};
}

std::vector<Sprite *> SampleStartScene::sprites() {
    return {  animation.get(), finalFantasyGuy.get() };
}

void SampleStartScene::load() {

}

void SampleStartScene::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }


}
