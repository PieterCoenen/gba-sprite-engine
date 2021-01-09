//
// Created by Pieter Coenen on 9/01/2021.
//

#include <vector>

#include "crewmate.h"

void Crewmate::interact() {

}

bool Crewmate::useItem(Item item) {
    if (std::find(std::begin(items), std::end(items), item)){
        return true;
    }else{
        return false;
    }
}