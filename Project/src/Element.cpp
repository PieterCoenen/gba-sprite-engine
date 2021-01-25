//
// Created by Pieter Coenen on 9/01/2021.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>
#include <vector>

#include "Item.h"
#include "Element.h"

bool Element::isInteractive(Element element){
    return true;
}

bool Element::hasItem(Element element){
    return true;
}

bool Element::needsItem(Element element, Item item){
    return true;
}
