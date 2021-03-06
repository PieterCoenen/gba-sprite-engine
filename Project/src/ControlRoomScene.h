//
// Created by Pieter Coenen on 11/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CONTROLROOMSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_CONTROLROOMSCENE_H


#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

class ControlRoomScene : public Scene{
private:
    std::unique_ptr<Sprite> avatar;

    std::unique_ptr<Background> bg;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ControlRoomScene(std::shared_ptr<GBAEngine> engine, std::string color) : Scene(engine) {
        this->color = color;
    }

    std::string color;

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_CONTROLROOMSCENE_H
