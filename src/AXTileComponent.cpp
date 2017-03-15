//
// Created by William Meaton on 01/09/2016.
//

#include "headers/AXTileComponent.hpp"
#include "headers/AXTile.hpp"

void AXTileComponent::setOwner(AXTile* owner) {
    if(owner){
        this->owner = owner;
    }
}

AXTile* AXTileComponent::getOwner() {
    return owner;
}

AXScene* AXTileComponent::getScene() {
    if(owner){
        return owner->getScene();
    }
    return 0;
}
