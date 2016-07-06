
//  RigidBody.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "RigidBody.hpp"
#include "Entity.hpp"

RigidBody::RigidBody(bool gravity): velocity(0, 0), drag(0.5, 0.5), gravity(gravity){
    
}

void RigidBody::update(){
    //get the last frame
    // previousVelocity = velocity;
    // wasGrounded = isGrounded;
    std::cout << velocity.x << std::endl;
    this->applyDrag();
        std::cout << velocity.x << std::endl;

    this->applyGravity();
        std::cout << velocity.x << std::endl;

    this->terminalVelocity();
        std::cout << velocity.x << std::endl;


    if(this->owner->getCollider()){
        //check and correct collisions
        this->owner->getCollider()->worldCollideCheck(velocity);
    }
    // move the entity (this will move the colliders too)
    // std::cout << "v0 " << previousVelocity.x << " " << previousVelocity.y << std::endl;
    this->owner->moveEntity(velocity);
    
    //see if the entity is touching the ground
    // if(owner->getTransform()->getPos().y+owner->getTransform()->getSize().y == Runner::getHeight()){
    //     isGrounded = true;
    // }else{
    //     isGrounded = false;
    // }
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

bool RigidBody::isMoving(){
    if(velocity.x != 0 || velocity.y != 0){
        return true;
    }else{
        return false;
    }
}

void RigidBody::setGravity(bool g){
    this->gravity = g;
}

void RigidBody::addForce(float x, float y){
    this->velocity.x += x;
    this->velocity.y += y;
    std::cout << "force";
}

void RigidBody::addForce(const Math::Vector2D& f){
    velocity += f;
}

const Math::Vector2D& RigidBody::getForce(){
    return velocity;
}

bool RigidBody::isOnGround(){
    return isGrounded;
}

void RigidBody::setForce(float x, float y){
    this->velocity.x = x;
    this->velocity.y = y;
}

void RigidBody::setForce(const Math::Vector2D& force){
    this->setForce(force.x, force.y);
}
