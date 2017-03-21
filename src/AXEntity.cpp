//
//  Axilya
//  AXEntity.cpp
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/AXEntity.hpp"
#include "headers/AXScene.hpp"

AXEntity::AXEntity(const std::string& name, float x, float y, float w, float h) : name(name){
    transform = new AXTransform(x, y, w, h);
    transform->setOwner(this);
    renderer = new AXRenderer();
    renderer->setOwner(this);
    audioPlayer = new AXAudioPlayer();
    audioPlayer->setOwner(this);
}

AXEntity::AXEntity(const std::string& name, const AXVector2D& pos, const AXVector2D& size) : name(name){
    transform = new AXTransform(pos, size);
    transform->setOwner(this);
    renderer = new AXRenderer();
    renderer->setOwner(this);
    audioPlayer = new AXAudioPlayer();
    audioPlayer->setOwner(this);
}

AXEntity::AXEntity(const std::string& name): name(name){
    transform = new AXTransform(0, 0, 0, 0);
    transform->setOwner(this);
    renderer = new AXRenderer();
    renderer->setOwner(this);
    renderer->setDrawType(AX_DRAW_NONE);
    audioPlayer = new AXAudioPlayer();
    audioPlayer->setOwner(this);
}

AXEntity::~AXEntity(){
    //Do not delete the texture, it's not handled by this object
    //remove all the components
    delete transform;
    transform = 0;
    delete collider;
    collider = 0;
    delete rigidBody;
    rigidBody = 0;
    delete renderer;
    renderer = 0;
    delete audioPlayer;
    audioPlayer = 0;
    for(auto c : components){
        delete c;
        c = 0;
    }
}

void AXEntity::start(){
    for(auto& c : components){
        c->start();
    }
}

void AXEntity::draw(const AXVector2D& renderOffset){
    if(renderer){
        renderer->draw(renderOffset);
    }
}
void AXEntity::update(){
    if(rigidBody){
        rigidBody->update();
    }
    for(auto& c : components){
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

void AXEntity::handle_eptr(std::exception_ptr eptr){
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}

void AXEntity::moveEntity(float x, float y){
    this->moveEntity(AXVector2D(x, y));
}

void AXEntity::resizeEntity(float w, float h){
    this->transform->getSize().x = w;
    this->transform->getSize().y = h;
    if(collider){
        collider->getBounds()->set(collider->getBounds()->getPosition().x, collider->getBounds()->getPosition().y, w, h);
    }
}

void AXEntity::moveEntity(AXVector2D v){
    AXVector2D newPos = transform->getPosition() + v;
    if(collider){
        //reset the current Collisions
        memset(currentCollisions, 0, 18);
        collider->getBounds()->set(newPos, collider->getBounds()->getSize());
        transform->set(newPos);
        //if the collider is screen bound
        if(collider->screenBound){
            // allow only two sceen collisions at once
            for(int i = 0; i < 2; i++){
                //get the result of the world collide
                currentCollisions[i] = collider->worldCollideCheck(v);
                //if the collision didn't happen, it means they've all been resolved
                if(currentCollisions[i] != 0){
                    this->onWorldCollision(currentCollisions[i]);
                }else{
                    break;
                }
            }
        }
        // check the collisions against other entities
        // the results will be written to the currentCollisions array
        scene->collideCheck(this, v, currentCollisions+2);
        //copy the collision data to the lastCollisions array
        memcpy(lastCollisions, currentCollisions, 18);
    }else{
        transform->set(newPos);
    }
}

AXEntity* AXEntity::clone(){
    AXEntity* e = new AXEntity(this->name, transform->getPosition(), transform->getSize());
    e->setLayer(this->layer);
    e->setCollisionLayer(this->collisionLayer);
    if(collider){
       e->addCollider(collider->clone());
       e->getCollider()->setOwner(e);
    }
    if(rigidBody){
        e->addRigidBody(rigidBody->clone());
        //because rigidbody returns a component, the exact values won't be copied
        e->getRigidBody()->setGravity(rigidBody->getGravity());
        e->getRigidBody()->setOwner(e);
    }
    for(auto& c : components){
        AXComponent* comp = c->clone();
        comp->setOwner(e);
        e->addComponent(comp);
    }
    //replace old renderer
    delete e->renderer;
    //get the new one
    e->renderer = this->renderer->clone();
    e->renderer->setColour(this->renderer->getColour());
    e->renderer->setOwner(e);

    delete e->audioPlayer;
    e->audioPlayer = this->audioPlayer->clone();
    e->audioPlayer->setOwner(e);

    e->active = this->active;
    e->dead = this->dead;
    return e;
}

void AXEntity::destroy(){
    this->dead = true;
}

void AXEntity::onWorldCollision(int direction){
    //When a collision with the world happens
    for(auto& c : components){
        c->onWorldCollision(direction);
    }

}


void AXEntity::onCollision(AXEntity* e, int direction){
    //when a collision happens
    for(auto& c : components){
        c->onCollision(e, direction);
        c->onCollision(e);
    }
}


void AXEntity::onClick(int mouseButton){
    for(auto& c : components){
        c->onClick(mouseButton);
    }
}

void AXEntity::onHover(){
    for(auto& c : components){
        c->onHover();
    }
}

void AXEntity::addComponent(AXComponent* c){
    if(c) {
        c->setOwner(this);
        components.push_back(c);
    }
}

void AXEntity::addRigidBody(AXRigidBody* r) {
    if (r) {
        if(rigidBody){
            delete rigidBody;
            rigidBody = 0;
        }
        r->setOwner(this);
        this->rigidBody = r;
    }
}

void AXEntity::addRigidBody(bool gravity){
    if(rigidBody){
        delete rigidBody;
        rigidBody = 0;
    }
    this->rigidBody = new AXRigidBody(gravity);
    this->rigidBody->setOwner(this);
}

bool AXEntity::isGrounded(){
    //first check if it's touched the bottom of the screen at all
    if(lastCollisions[0] == AX_COLLIDE_DOWN || lastCollisions[1] == AX_COLLIDE_DOWN){
        return true;
    }else{
        //loop through the last set of collisions and check for a top hit (aka the bottom of this hit the top of something)
        for(int i = 0; i < 16; i++){
            if(lastCollisions[i+2] == AX_COLLIDE_UP){
                return true;
            }
        }
    }
    return false;
}

AXRigidBody* AXEntity::getRigidBody(){
    return rigidBody;
}

AXTransform* AXEntity::getTransform(){
    return transform;
}

void AXEntity::addCollider(AXCollider* c){
    if(c){
        if(collider){
            delete collider;
            collider = 0;
        }
        c->setOwner(this);
        //this is temporary, it was causing a seg fault if set in the AXBoxCollider constructor 
        //because owner was not set until after the creation of the collider
        c->bounds = new AXRect(transform->getPosition(), transform->getSize());
        c->center = AXVector2D(transform->getPosition()+(transform->getSize()/2));
        c->halfSize = transform->getSize()/2;
        this->collider = c;
    }
}

void AXEntity::onDestroy(){
    for(auto& c : components){
        c->onDestroy();
    }
    delete this;
}

void AXEntity::setDrawType(int type){
    this->renderer->setDrawType(type);
}

int AXEntity::getDrawType(){
    return this->renderer->getDrawType();
}

void AXEntity::setName(const std::string& name){
    this->name = name;
}

AXScene* AXEntity::getScene(){
    return scene;
}

void AXEntity::setScene(AXScene* s){
    this->scene = s;
}

void AXEntity::setActive(bool a){
    this->active = a;
}

bool AXEntity::isActive(){
    return this->active;
}

AXCollider* AXEntity::getCollider(){
    return collider;
}

bool AXEntity::isDead(){
    return dead;
}

int AXEntity::getLayer(){
    return layer;
}

void AXEntity::setLayer(int layer){
    this->layer = layer;
}


void AXEntity::setCollisionLayer(int layer){
    if(layer > 17){
        layer = 17;
    }
    if(layer < -1){
        layer = -1;
    }
    this->collisionLayer = layer;
}

int AXEntity::getCollisionLayer(){
    return this->collisionLayer;
}

std::string& AXEntity::getName(){
    return this->name;
}

AXRenderer* AXEntity::getRenderer() {
    return renderer;
}

AXAudioPlayer* AXEntity::getAudioPlayer(){
    return audioPlayer;
}

void AXEntity::setColour(float r, float g, float b, float a){
    renderer->setColour(r, g, b, a);
}

void AXEntity::setColour(float r, float g, float b){
    renderer->setColour(r, g, b, 255);
}

void AXEntity::setColour(const AXColour& c){
    renderer->setColour(c.getR(), c.getG(), c.getB(), c.getA());
}

AXColour& AXEntity::getColour(){
    return renderer->getColour();
}
