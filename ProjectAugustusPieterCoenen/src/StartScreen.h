//
// Created by Pieter Coenen on 3/07/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCREEN_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

class StartScreen : public Scene {
private:
    std::vector<std::string> colors;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    StartScreen(const std::shared_ptr<GBAEngine> &engine);

    std::string color;

    void load() override;
    void tick(u16 keys) override;

};

#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCREEN_H
