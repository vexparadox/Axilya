//
//  Component.cpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/Component.hpp"
#include "headers/Entity.hpp"

Component::Component(){
}

Component::~Component(){
}

Entity* Component::getOwner(){
    return owner;
}

Scene* Component::getScene() {
    return owner->getScene();
}

void Component::setOwner(Entity* o){
    this->owner = o;
    this->transform = owner->getTransform();
}
