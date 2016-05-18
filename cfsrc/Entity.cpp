//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"
Entity::Entity(float x, float y){
    transform = new Transform(Math::Vector2D(x, y), this);
}

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
        std::cout << "Drawing image: " << texture->getTextureID() << std::endl;
        texture->draw(transform->getPos());
    }else{
        Graphics::fill(0.0f);
        Graphics::drawRect(transform->getPos(), 10, 10);
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