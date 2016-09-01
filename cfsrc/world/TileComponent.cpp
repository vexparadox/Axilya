//
// Created by William Meaton on 01/09/2016.
//

#include "TileComponent.hpp"
#include "Tile.hpp"

void TileComponent::setOwner(Tile* owner) {
    if(owner){
        this->owner = owner;
    }
}

Tile* TileComponent::getOwner() {
    return owner;
}

Scene* TileComponent::getScene() {
    if(owner){
        return owner->getScene();
    }
    return 0;
}