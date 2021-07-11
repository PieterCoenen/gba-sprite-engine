//
// Created by Pieter Coenen on 7/07/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FARMER_H
#define GBA_SPRITE_ENGINE_PROJECT_FARMER_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>
#include "Tool.h"


class Farmer {
private:
    std::vector<Tool> tools;

public:
    Tool equipedTool;
    bool toolEquiped;

    void plantCrop(Crop crop);

    void harvestCrop(Crop crop);

    void equipTool(Tool tool);

    void dequipTool(Tool emptyTool);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_FARMER_H
