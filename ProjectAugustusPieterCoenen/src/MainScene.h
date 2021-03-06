//
// Created by Pieter Coenen on 3/07/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MAINSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_MAINSCENE_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

class MainScene : public Scene {
private:
    std::unique_ptr<Sprite> avatar;

    std::unique_ptr<Background> bg;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    MainScene(const std::shared_ptr<GBAEngine> &engine);


    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MAINSCENE_H
