//
//  Component.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Component.hpp"

Component::Component(Entity* owner) : owner(owner){
    
}

Component::~Component(){
}

Entity* Component::getOwner(){
    return owner;
}

void Component::setOwner(Entity* o){
    this->owner = o;
}