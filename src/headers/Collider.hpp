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
 * This is a base class for Colliders that detect and resolve collisions between Entities and Worlds.
 */
#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "Types.h"
class Entity;
class Collider{
public:
    Math::Vector2D center, halfSize;
    Shape* bounds;
    Entity* owner = 0;
    bool screenBound;
    /*!
    * The constuctor of the base class Collider.
    *
    * The bounds of this Collider will default to those defined by the Entity's Transform Component.
    */    
    Collider();
    virtual ~Collider();
    /*!
    * A method to get the bounds of this Collider.
    *
    * @return The Shape of this Collider's bounds
    */    
    Shape* getBounds();
    /*!
    * A method to set the Entity that owns this Collider.
    *
    * @param e The owner of this Collider
    */   
    void setOwner(Entity* e);
    /*!
    * A method to get the Entity that owns this Collider.
    *
    * @return The owner of this Collider
    */   
    Entity* getOwner();
    /*!
    * A virtual method to check the mouse position against this Collider's bounds.
    */
    virtual void mouseCheck() = 0;
    /*!
    * A virtual method to check this Collider's bounds against the screen and World.
    *
    * @return Will return the direction of the collision that happened AX_COLLIDE_UP/DOWN/RIGHT/LEFT or 0 if none occurred.
    */
    virtual int worldCollideCheck(Math::Vector2D&) = 0;
    /*!
    * A virtual method to check this Collider's bounds against another Entity's Collider.
    *
    * @return Will return the direction of the collision that happened AX_COLLIDE_UP/DOWN/RIGHT/LEFT or 0 if none occurred.
    */
    virtual int checkMovement(Entity*, Math::Vector2D&) = 0;
    /*!
    * A virtual method to clone this Collider.
    *
    * @return a clone of this Collider.
    */
    virtual Collider* clone() = 0;
};	

#endif