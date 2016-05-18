//
//  RigidBody.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "RigidBody.hpp"
#include "Entity.hpp"

RigidBody::RigidBody(Entity* owner) : Component(owner), acceleration(0, 0){
    
}

void RigidBody::update(){
    if(gravity){
        if(acceleration.y > terminalVelocity){
            acceleration.y = terminalVelocity;
        }else{
            acceleration.y += 0.2;
        }
    }
    if(!getOwner()->getCollider()){
        // std::cout << "No Collider" << std::endl;
    }
    getOwner()->getTransform()->getPos() + this->acceleration;
}