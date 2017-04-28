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
 * This is a pre-built Entity AXComponent that describes the position and size of an AXEntity.
 * This is created by default for all Entities.
 */
#ifndef AXTransform_hpp
#define AXTransform_hpp

#include <stdio.h>
#include "AXComponent.hpp"
class AXEntity;
class AXTransform : public AXComponent{
    AXVector2D position, size, lastPosition;
    AXTransform(const AXTransform& t) = delete;
    AXTransform(const AXTransform&& t) = delete;
    AXTransform& operator= (const AXTransform& o) = delete;
public:
    /*!
    * Constructor of the AXTransform
    * This is called automatically by the AXEntity constructor
    * @param pos the Entities position
    * @param size the Entities size
    * @see AXEntity constructor
    */
    AXTransform(const AXVector2D& pos, const AXVector2D& size);
    AXTransform(float x, float y, float w, float h);
    /*!
    * Sets the transforms parameters
    */
    void set(const AXVector2D &v, const AXVector2D &s);

    void set(float x, float y, float w, float h);
    /*!
    * Sets the transforms position only
    */
    void set(const AXVector2D &v);
    /*!
    * Sets the transforms position only
    */
    void set(float x, float y);
    /*!
    * Moves the transform
    */
    void moveTransform(const AXVector2D &v);
    /*!
    * Returns the position
    * @return the position of the AXEntity
    */
    AXVector2D& getPosition();
    /*!
    * Returns the size
    * @return the size of the AXEntity
    */
    AXVector2D& getSize();

    float getWidth();
    float getHeight();

    AXComponent* clone();
};
#endif /* Transform_hpp */
