//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"
Entity::Entity(float x, float y, float w, float h){
    transform = new Transform(x, y, w, h, this);
}

Entity::Entity(const Math::Vector2D& pos, const Math::Vector2D& size){
    transform = new Transform(pos, size, this);
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
        // Graphics::fill(255, 255, 255, 255);
        texture->draw(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }else{
        Graphics::fill(0, 0, 0, 255);
        Graphics::drawRect(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }
}

void Entity::addTexture(std::string s){
    this->texture = new Graphics::Image(s);
}

void Entity::addTexture(Graphics::Image* i){
    this->texture = i;
}

void Entity::addCollider(Collider* c){
    this->collider = c;
}

Graphics::Image* Entity::getTexture(){
    return this->texture;
}

Collider* Entity::getCollider(){
    return this->collider;
}