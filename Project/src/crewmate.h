//
// Created by Pieter Coenen on 9/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CREWMATE_H
#define GBA_SPRITE_ENGINE_PROJECT_CREWMATE_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

#include "Item.h"

class Crewmate{
private:
    std::string color;

public:
    Crewmate();

    std::vector<std::string> items;

    void interact();

    bool useItem(std::string item);

    bool interactableItem();
};




#endif //GBA_SPRITE_ENGINE_PROJECT_CREWMATE_H
