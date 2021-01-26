//
// Created by Pieter Coenen on 10/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

class StartScene : public Scene {
private:
    std::vector<std::string> colors;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    StartScene(const std::shared_ptr<GBAEngine> &engine);

    std::string color;

    void load() override;
    void tick(u16 keys) override;

    void fillColors();

};


#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
