//
// Created by Pieter Coenen on 9/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ELEMENT_H
#define GBA_SPRITE_ENGINE_PROJECT_ELEMENT_H

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

#include "Item.h"

class Element{
public:
    bool isInteractive(Element element);
    bool hasItem(Element element);

    Element(Item item);

    bool needsItem(Element element, Item item);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ELEMENT_H
