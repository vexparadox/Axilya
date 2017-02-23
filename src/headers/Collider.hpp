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
    //take the owner and bounds of the collider 
    Collider();
    virtual ~Collider();
    Shape* getBounds();
    void setOwner(Entity* e);
    Entity* getOwner();
    virtual void mouseCheck() = 0;
    virtual int worldCollideCheck(Math::Vector2D&) = 0;
    virtual int checkMovement(Entity*, Math::Vector2D&) = 0;
    virtual Collider* clone() = 0;
};	

#endif