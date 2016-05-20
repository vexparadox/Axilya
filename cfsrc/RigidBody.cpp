//
//  RigidBody.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "RigidBody.hpp"
#include "Entity.hpp"

RigidBody::RigidBody(Entity* owner, bool gravity) : Component(owner), velocity(0, 0), drag(0.5, 0.5), gravity(gravity){
    
}

void RigidBody::update(){
    this->applyDrag();
    this->applyGravity();
    this->terminalVelocity();
    std::cout << "X: " << velocity.x << " Y: " << velocity.y << std::endl;

    this->owner->getCollider()->collideCheck(velocity);
    this->owner->getTransform()->getPos()+this->velocity;
}

void RigidBody::applyGravity(){
    if(gravity){
        velocity.y += 1;
    }
}

void RigidBody::terminalVelocity(){
    if(velocity.x > maxVelocityX){
        velocity.x = maxVelocityX;
    }else if(velocity.x < - maxVelocityX){
        velocity.x = -maxVelocityX;
    }
    if(velocity.y > maxVelocityY){
        velocity.y = maxVelocityY;
    }else if(velocity.y < -maxVelocityY){
        velocity.y = -maxVelocityY;
    }
}

void RigidBody::applyDrag(){
    if(velocity.y > 0){
        velocity.y -= drag.y;
    }else if(velocity.y < 0){
        velocity.y += drag.y;
    }
    if(velocity.x > 0){
        velocity.x -= drag.x;
    }else if(velocity.x < 0){
        velocity.x += drag.x;
    }
}

void RigidBody::setGravity(bool g){
    this->gravity = g;
}

void RigidBody::addForce(float x, float y){
    this->velocity.x += x;
    this->velocity.y += y;
}

void RigidBody::addForce(const Math::Vector2D& f){
    velocity += f;
}