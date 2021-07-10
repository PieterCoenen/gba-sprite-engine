//
// Created by Pieter Coenen on 10/07/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TOOL_H
#define GBA_SPRITE_ENGINE_PROJECT_TOOL_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>
#include "Crop.h"

class Tool {
private:
    std::vector<Crop> crops;
    int timeSaved;

public:
    std::string name;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_TOOL_H
