//
// Created by Pieter Coenen on 9/01/2021.
//

#include <string>
#include <algorithm>

#include "crewmate.h"

bool Crewmate::useItem(std::string item) {
    if (std::find(items.begin(), items.end(), item) != items.end()){
        return true;
    }else{
        return false;
    }
}