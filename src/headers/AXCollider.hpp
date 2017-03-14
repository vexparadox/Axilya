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
 * This is a base class for AXColliders that detect and resolve collisions between Entities and Worlds.
 */
#ifndef AXCollider_hpp
#define AXCollider_hpp

#include <stdio.h>
#include "Types.h"
class AXEntity;
class AXCollider{
public:
    Math::Vector2D center, halfSize;
    Shape* bounds;
    AXEntity* owner = 0;
    bool screenBound;
    /*!
    * The constuctor of the base class AXCollider.
    *
    * The bounds of this AXCollider will default to those defined by the AXEntity's AXTransform AXComponent.
    */    
    AXCollider();
    virtual ~AXCollider();
    /*!
    * A method to get the bounds of this AXCollider.
    *
    * @return The Shape of this AXCollider's bounds
    */    
    Shape* getBounds();
    /*!
    * A method to set the AXEntity that owns this AXCollider.
    *
    * @param e The owner of this AXCollider
    */   
    void setOwner(AXEntity* e);
    /*!
    * A method to get the AXEntity that owns this AXCollider.
    *
    * @return The owner of this AXCollider
    */   
    AXEntity* getOwner();
    /*!
    * A virtual method to check the mouse position against this AXCollider's bounds.
    */
    virtual void mouseCheck() = 0;
    /*!
    * A virtual method to check this AXCollider's bounds against the screen and World.
    *
    * @return Will return the direction of the collision that happened AX_COLLIDE_UP/DOWN/RIGHT/LEFT or 0 if none occurred.
    */
    virtual int worldCollideCheck(Math::Vector2D&) = 0;
    /*!
    * A virtual method to check this AXCollider's bounds against another AXEntity's AXCollider.
    *
    * @return Will return the direction of the collision that happened AX_COLLIDE_UP/DOWN/RIGHT/LEFT or 0 if none occurred.
    */
    virtual int checkMovement(AXEntity*, Math::Vector2D&) = 0;
    /*!
    * A virtual method to clone this AXCollider.
    *
    * @return a clone of this AXCollider.
    */
    virtual AXCollider* clone() = 0;
};	

#endif