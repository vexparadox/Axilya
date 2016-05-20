//
//  RigidBody.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "RigidBody.hpp"
#include "Entity.hpp"

RigidBody::RigidBody(Entity* owner, bool gravity) : Component(owner), velocity(0, 0), drag(0.1, 0.1), gravity(gravity){
    
}

void RigidBody::update(){
    // this->applyDrag();
    this->applyGravity();
    this->owner->getCollider()->collideCheck(velocity);
    this->owner->getTransform()->getPos()+this->velocity;
}

void RigidBody::applyGravity(){
    if(gravity){
        if(velocity.y >= terminalVelocity){
            velocity.y = terminalVelocity; 
        }else{
            velocity.y += 0.981;
        }
    }
}

void RigidBody::applyDrag(){
    if(velocity.y > 0){
        velocity.y -= drag.y;
    }else{
        velocity.y += drag.y;
    }
    if(velocity.x > 0){
        velocity.x -= drag.x;
    }else{
        velocity.x += drag.x;
    }
    if(Math::absolute(velocity.x) < 0.2){
        velocity.x = 0;
    }
    if(Math::absolute(velocity.y) < 0.2){
        velocity.y = 0;
    }
}

void RigidBody::setGravity(bool g){
    this->gravity = g;
}