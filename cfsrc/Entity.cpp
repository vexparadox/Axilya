//
//  closedFrameworks
//  Entity.cpp
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"
#include "Scene.hpp"

Entity::Entity(const std::string& name, float x, float y, float w, float h){
    transform = new Transform(x, y, w, h);
    transform->setOwner(this);
    this->name = name;
}

Entity::Entity(const std::string& name, const Math::Vector2D& pos, const Math::Vector2D& size){
    transform = new Transform(pos, size);
    transform->setOwner(this);
    this->name = name;
}

Entity::~Entity(){
    //Do not delete the texture, it's not handled by this object
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
        Graphics::fill(255, 255, 255, 255);
        texture->getImage()->draw(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }else{
        Graphics::fill(colour);
        Graphics::drawRect(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }
}
void Entity::update(){
    if(rigidBody){
        rigidBody->update();
    }
    for(auto c : components){
        //handles exceptions in user made components to a certain degree
        std::exception_ptr eptr;
        //attempt to update the components
        try {  
            c->update();
        }catch(...) {
            //catch an exception if it's thrown
            eptr = std::current_exception();
        }
        //handle the exception if there is one
        handle_eptr(eptr);
    }
    if(collider){
        //call a mouse check
        //has to be caught because using user codes
        std::exception_ptr eptr;
        try {  
            collider->mouseCheck();
        }catch(...) {
            eptr = std::current_exception();
        }
        handle_eptr(eptr);
    }
}

void Entity::handle_eptr(std::exception_ptr eptr){
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}


void Entity::moveEntity(Math::Vector2D v){
    if(collider){
	    // std::cout << "Before " << v.x << " " << v.y << std::endl;
        scene->collideCheck(this, v);
        v += transform->getPos();
	    // std::cout << "After" << v.x << " " << v.y << std::endl;
        collider->getBounds()->set(v, collider->getBounds()->getSize());
        transform->set(v);
    }else{
        v += transform->getPos();
        transform->set(v);
    }
}

void Entity::destroy(){
    this->dead = true;
}

void Entity::onCollision(Entity* e){
    //when a collision happens
    for(auto c : components){
        c->onCollision(e);
    }
}

void Entity::onClick(int mouseButton){
    for(auto c : components){
        c->onClick(mouseButton);
    }
}

void Entity::onHover(){
    for(auto c : components){
        c->onHover();
    }
}

void Entity::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void Entity::setColour(const Graphics::Colour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

const Graphics::Colour& Entity::getColour(){
    return colour;
}

Scene* Entity::getScene(){
    return scene;
}

void Entity::setScene(Scene* s){
    this->scene = s;
}

void Entity::setActive(bool a){
    this->active = a;
}

bool Entity::isActive(){
    return this->active;
}

void Entity::addComponent(Component* c){
    if(c) {
        c->setOwner(this);
        components.push_back(c);
    }
}

void Entity::addRigidBody(RigidBody* r) {
    if (r) {
        if(rigidBody){
            delete rigidBody;
            rigidBody = 0;
        }
        r->setOwner(this);
        this->rigidBody = r;
    }
}

void Entity::addRigidBody(bool gravity){
    if(rigidBody){
        delete rigidBody;
        rigidBody = 0;
    }
    this->rigidBody = new RigidBody(gravity);
    this->rigidBody->setOwner(this);
}

RigidBody* Entity::getRigidBody(){
    return rigidBody;
}

Transform* Entity::getTransform(){
    return transform;
}

void Entity::addTexture(Texture* t){
    if(t){
        if(texture){
            delete texture;
            texture = 0;
        }
        this->texture = t;
    }
}

void Entity::addTexture(int textureID){
    if(resourceManager->getTexture(textureID)){
        this->texture = resourceManager->getTexture(textureID);
    }
}

void Entity::addCollider(Collider* c){
    if(c){
        if(collider){
            delete collider;
            collider = 0;
        }
        c->setOwner(this);
        //this is temporary, it was causing a seg fault if set in the BoxCollider constructor 
        //because owner was not set until after the creation of the collider
        c->bounds = new Graphics::Rect(transform->getPos(), transform->getSize());
        c->center = Math::Vector2D(transform->getPos()+(transform->getSize()/2));
        c->halfSize = transform->getSize()/2;
        this->collider = c;
    }
}

Texture* Entity::getTexture(){
    return this->texture;
}

Collider* Entity::getCollider(){
    return collider;
}

bool Entity::isDead(){
    return dead;
}

std::string& Entity::getName(){
    return this->name;
}