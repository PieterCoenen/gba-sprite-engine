//
// Created by Pieter Coenen on 7/07/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CROP_H
#define GBA_SPRITE_ENGINE_PROJECT_CROP_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>
#include "Tool.h"

class Crop {
private:
    int timeToHatch;
    std::vector<Tool> tools;

public:
    std::string name;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_CROP_H
