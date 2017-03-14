//  AXRigidBody.cpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//
#include "headers/AXRigidBody.hpp"
#include "headers/AXEntity.hpp"

AXRigidBody::AXRigidBody(bool gravity): velocity(0, 0), drag(0.5, 0.5), gravity(gravity){
    maxVelocityY = 30;
    maxVelocityX = 7;
    maxFallingVelocity = 9;
}

void AXRigidBody::update(){
    //get the last frame
    previousVelocity = velocity;
    this->applyDrag();
    this->applyGravity();
    this->terminalVelocity();
    this->owner->moveEntity(velocity);
}

void AXRigidBody::applyGravity(){
    if(gravity){
        velocity.y += 1;
    }
}

void AXRigidBody::terminalVelocity(){
    if(velocity.x > maxVelocityX){
        velocity.x = maxVelocityX;
    }else if(velocity.x < - maxVelocityX){
        velocity.x = -maxVelocityX;
    }
    if(velocity.y > maxFallingVelocity){
        velocity.y = maxFallingVelocity;
    }
    if(velocity.y < -maxVelocityY){
        velocity.y = -maxVelocityY;
    }
}

void AXRigidBody::applyDrag(){
    if(velocity.x < drag.x && velocity.x > drag.x){
        velocity.x = 0;
    }else if(velocity.y > 0){
        velocity.y -= drag.y;
    }else if(velocity.y < 0){
        velocity.y += drag.y;
    }
    if(velocity.y < drag.y && velocity.y > drag.y){
        velocity.y = 0;
    }else if(velocity.x > 0){
        velocity.x -= drag.x;
    }else if(velocity.x < 0){
        velocity.x += drag.x;
    }
}

bool AXRigidBody::isMoving(){
    return (velocity.x != 0 && velocity.y != 0);
}

void AXRigidBody::setGravity(bool g){
    this->gravity = g;
}

bool AXRigidBody::getGravity(){
    return this->gravity;
}

void AXRigidBody::addForce(float x, float y){
    this->velocity.x += x;
    this->velocity.y += y;
}

void AXRigidBody::addForce(const Math::Vector2D& f){
    velocity += f;
}

const Math::Vector2D& AXRigidBody::getForce(){
    return velocity;
}

void AXRigidBody::setDrag(float x, float y){
    this->drag.x = x;
    this->drag.y = y;
}

void AXRigidBody::setDrag(const Math::Vector2D& drag){
    this->drag = drag;
}

void AXRigidBody::setForce(float x, float y){
    this->velocity.x = x;
    this->velocity.y = y;
}

void AXRigidBody::setForce(const Math::Vector2D& force){
    this->setForce(force.x, force.y);
}
AXComponent* AXRigidBody::clone(){
    return new AXRigidBody(this->gravity);
}
