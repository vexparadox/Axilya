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
 * This is a pre-built Entity Component that describes the position and size of an Entity.
 * This is created by default for all Entities.
 */
#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "Component.hpp"
class Entity;
class Transform : public Component{
    Math::Vector2D position, size, lastPosition;
public:
    /*!
    * Constructor of the Transform
    * This is called automatically by the Entity constructor
    * @param pos the Entities position
    * @param size the Entities size
    * @see Entity constructor
    */
    Transform(const Math::Vector2D& pos, const Math::Vector2D& size);
    Transform(float x, float y, float w, float h);
    /*!
    * Sets the transforms parameters
    */
    void set(const Math::Vector2D &v, const Math::Vector2D &s);

    void set(float x, float y, float w, float h);
    /*!
    * Sets the transforms position only
    */
    void set(const Math::Vector2D &v);
    /*!
    * Sets the transforms position only
    */
    void set(float x, float y);
    /*!
    * Moves the transform
    */
    void moveTransform(const Math::Vector2D &v);
    /*!
    * Returns the position
    * @return the position of the Entity
    */
    Math::Vector2D& getPosition();
    /*!
    * Returns the size
    * @return the size of the Entity
    */
    Math::Vector2D& getSize();

    float getWidth();
    float getHeight();

    Component* clone();
};
#endif /* Transform_hpp */
