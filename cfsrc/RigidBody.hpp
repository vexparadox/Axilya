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
    float maxVelocityY = 6, maxVelocityX = 6;
    void applyDrag();
    void applyGravity();
    void terminalVelocity();
public:
    /*!
    * Adds a force to the rigid body 
    * @param owner the Entity which this component belongs too
    * @param gravity wheather this RigidBody has gravity
    */
    RigidBody(Entity* owner, bool gravity);
    /*!
    * Adds a force to the rigid body 
    * @param x directional force
    * @param y directional force
    * @see RigidBody::addForce(cont Math::Vector2D& force)
    */
    void addForce(float x, float y);
    void addForce(const Math::Vector2D& force);
    /*!
    * Called every game loop
    * Called from the Entity which owns this component
    */
    void update();
    /*!
    * A method to set the gravity value
    */
    void setGravity(bool);
};


#endif /* RigidBody_hpp */
