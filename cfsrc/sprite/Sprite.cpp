//
// Created by William Meaton on 02/09/2016.
//

#include "Sprite.hpp"

Sprite::Sprite(const std::string &name) {
    this->name = name;
}

std::string Sprite::getName() {
    return this->name;
}