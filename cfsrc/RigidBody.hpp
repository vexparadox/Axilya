//
//  RigidBody.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <stdio.h>
#include "Component.hpp"


class RigidBody : public Component{
    bool gravity;
    Math::Vector2D velocity, drag;
    float terminalVelocity = 2;
    void applyDrag();
    void applyGravity();
public:
    RigidBody(Entity*, bool);
    void addForce(float, float);
    void addForce(const Math::Vector2D&);
    void update();
    void setGravity(bool);
};


#endif /* RigidBody_hpp */
