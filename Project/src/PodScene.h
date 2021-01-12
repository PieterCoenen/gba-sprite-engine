#ifndef GBA_SPRITE_ENGINE_SAMPLE_START_SCENE_H
#define GBA_SPRITE_ENGINE_SAMPLE_START_SCENE_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

class PodScene : public Scene {
private:
    std::unique_ptr<Sprite> avatar;

    std::unique_ptr<Sprite> keyCard;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    PodScene(std::shared_ptr<GBAEngine> engine, std::string color) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_SAMPLE_START_SCENE_H
