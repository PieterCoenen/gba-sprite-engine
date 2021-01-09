#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "pod_scene.h"

std::vector<Background *> PodScene::backgrounds() {
    return {};
}

std::vector<Sprite *> PodScene::sprites() {
    return {};
}

void PodScene::load() {
    engine.get()->enableText();
}

void PodScene::tick(u16 keys) {

}
