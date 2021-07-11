//
// Created by Pieter Coenen on 6/07/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_INVENTORYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_INVENTORYSCENE_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

class InventoryScene : public Scene {
private:


public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    InventoryScene(const std::shared_ptr<GBAEngine> &engine, std::string scene) : Scene(engine) {
        this->scene = scene;
    }

    std::string scene;

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_INVENTORYSCENE_H
