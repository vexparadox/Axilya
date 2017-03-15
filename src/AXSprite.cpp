//
// Created by William Meaton on 02/09/2016.
//

#include "headers/AXSprite.hpp"

AXSprite::AXSprite(const std::string &name) {
    this->name = name;
}

std::string AXSprite::getName() {
    return this->name;
}