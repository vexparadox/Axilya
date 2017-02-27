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
 * This class describes a BoxCollider, it holds instructions for detecting and resolving collisions using rectangle bounds.
 */
#ifndef BoxCollider_h
#define BoxCollider_h

#include "Collider.hpp"
#include "AXWindow.hpp"
#include "CollideDirections.hpp"
class Entity;
class BoxCollider : public Collider{
public:
    /*!
    * The constructor of a BoxCollider
    *
    * The bounds of this Collider will default to those defined by the Entity's Transform Component.
    */
    BoxCollider();
	/*!
    * A method to check this Collider's bounds against the screen (if screen bound) and the World and correct collisions that occur.
    *
    * This method will be called repeatedly until it returns 0.
    * @param v the proposed movement of this Entity, the values will be set to 0 if a collision occurs.
    * @return Will return the direction of the collision that happened AX_COLLIDE_UP/DOWN/RIGHT/LEFT or 0 if none occurred.
    */
    int worldCollideCheck(Math::Vector2D& v);
	/*!
    * A method to check this Collider's bounds against the  and correct collisions that occur.
    *
    * This method will be called repeatedly until it returns 0 and will only be called if e has a Collider.
    * @param e the Entity that is checked against this Collider's bounds
    * @param v the proposed movement of e, the values will be set to 0 if a collision occurs.
    * @return Will return the direction of the collision that happened AX_COLLIDE_UP/DOWN/RIGHT/LEFT or 0 if none occurred.
    */
    int checkMovement(Entity* e, Math::Vector2D& v);
	/*!
    * A method to check the mouse position is over this Collider's bounds.
    *
    * This method will call onClick() and onHover() on this Collider's Entity
    */
    void mouseCheck();
	/*!
    * A method to clone this Collider.
    *
    * @return A clone of this BoxCollider
    */
    Collider* clone();
};

#endif
