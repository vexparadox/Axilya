/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This is a pre-built Entity AXComponent that gives the simulation of gravity and mass.
 */
#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <stdio.h>
#include "AXComponent.hpp"

class AXRigidBody : public AXComponent{
    bool gravity;
    AXVector2D velocity, drag, previousVelocity;
    float maxVelocityY, maxVelocityX, maxFallingVelocity;
    void applyDrag();
    void applyGravity();
    void terminalVelocity();
public:
    /*!
    * Adds a force to the rigid body 
    * @param gravity wheather this AXRigidBody has gravity
    */
    AXRigidBody(bool gravity);
    /*!
    * Adds a force to the rigid body 
    * @param x directional force
    * @param y directional force
    * @see AXRigidBody::addForce(cont AXVector2D& force)
    */
    void addForce(float x, float y);
    void addForce(const AXVector2D& force);
    const AXVector2D& getForce();
    /*!
    * Sets the force on an object
    */
    void setForce(const AXVector2D& force);
    void setForce(float x, float y);

    void setDrag(const AXVector2D& drag);
    void setDrag(float x, float y);
    /*!
    * returns if this rigidbody is moving
    */
    bool isMoving();
    /*!
    * Called every game loop
    * Called from the AXEntity which owns this component
    */
    void update();
    /*!
    * A method to set the gravity value
    */
    void setGravity(bool);
    bool getGravity();
    AXComponent* clone();
};


#endif /* RigidBody_hpp */
