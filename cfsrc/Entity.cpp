//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"
#include "Scene.hpp"
Entity::Entity(float x, float y, float w, float h){
    transform = new Transform(x, y, w, h);
    transform->setOwner(this);
}

Entity::Entity(const Math::Vector2D& pos, const Math::Vector2D& size){
    transform = new Transform(pos, size);
    transform->setOwner(this);
}

Entity::~Entity(){
    //remove all the components
    delete transform;
    transform = 0;
    delete collider;
    collider = 0;
    delete rigidBody;
    rigidBody = 0;
    for(auto c : components){
        delete c;
        c = 0;
    }
}

void Entity::draw(){
    if(texture){
        // Graphics::fill(255, 255, 255, 255);
        std::cout << "Drawing texture" << std::endl;
        texture->draw(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }else{
        Graphics::fill(0, 0, 0, 255);
        Graphics::drawRect(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }
}
void Entity::update(){
    if(rigidBody){
        rigidBody->update();
    }
    for(auto c : components){
        c->update();
    }
}
void Entity::moveEntity(const Math::Vector2D &v){
    transform->moveTransform(v);
    if(collider){
        collider->getBounds()->moveShape(v);
    }
}

void Entity::onCollision(Entity* e){
    //when a collision happens
    for(auto c : components){
        c->onCollision(e);
    }
}

Scene* Entity::getScene(){
    return scene;
}

void Entity::setScene(Scene* s){
    this->scene = s;
}

void Entity::addComponent(Component* c){
    c->setOwner(this);
    components.push_back(c);
}

void Entity::addRigidBody(RigidBody* r){
    r->setOwner(this);
    this->rigidBody = r;
}

void Entity::addRigidBody(bool gravity){
    this->rigidBody = new RigidBody(gravity);
    this->rigidBody->setOwner(this);
}

RigidBody* Entity::getRigidBody(){
    return rigidBody;
}

Transform* Entity::getTransform(){
    std::cout << transform;
    if(transform){
        return transform;
    }
    return 0;
}

void Entity::addTexture(std::string s){
    this->texture = new Graphics::Image(s);
}

void Entity::addTexture(Graphics::Image* i){
    this->texture = i;
}

void Entity::addCollider(Collider* c){
    if(c){
        c->setOwner(this);
        //this is temporary, it was causing a seg fault if set in the BoxCollider constructor 
        //because owner was not set until after the creation of the collider
        c->bounds = new Graphics::Rect(transform->getPos(), transform->getSize());
        this->collider = c;
    }
}

Graphics::Image* Entity::getTexture(){
    return this->texture;
}

Collider* Entity::getCollider(){
    return collider;
}