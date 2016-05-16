//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(const Math::Vector2D& pos){
    transform = new Transform(pos, this);
}

void Entity::addComponent(Component* c){
    components.push_back(c);
}

Transform* Entity::getTransform(){
    return transform;
}

void Entity::update(){
    for(auto c : components){
        c->update();
    }
}

void Entity::draw(){
    if(texture){
        texture->draw(transform->getPos());
    }
}

void Entity::addTexture(std::string s){
    this->texture = new Graphics::Image(s);
}

void Entity::addTexture(Graphics::Image* i){
    this->texture = i;
}

Graphics::Image* Entity::getTexture(){
    return this->texture;
}