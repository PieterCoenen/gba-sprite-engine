//
// Created by Pieter Coenen on 7/07/2021.
//

#include "Farmer.h"


void Farmer::plantCrop(Crop crop) {

}

void Farmer::harvestCrop(Crop crop) {

}

void Farmer::equipTool(Tool tool) {
    Farmer::equipedTool = tool;
    Farmer::toolEquiped = true;
}

void Farmer::dequipTool(Tool emptyTool) {
    Farmer::equipedTool = emptyTool;
    Farmer::toolEquiped = false;
}