//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(){
    addComponent(new Transform);
}

Entity::Entity(const Math::Vector2D& pos){
    transform = new Transform(pos);
}

void Entity::addComponent(Component* c){
    components.push_back(c);
}

Transform* Entity::getTransform(){
    return transform;
}

void Entity::update(){
    
}