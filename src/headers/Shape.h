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
 * This is the base class for all shapes used in collision and rendering.
 */
#ifndef Shape_H
#define Shape_H
#include "Vector2D.h"
class Shape{
protected:
    Math::Vector2D position, size;
public:
    /*!
    * Constructor of Shapes
    * Rects, Ellipses (and Triangles) are Shapes
    * @param v the center position of the Shape
    */
    Shape(const Math::Vector2D& v, const Math::Vector2D& size){
        this->position = v;
        this->size = size;
    }
    virtual ~Shape(){};
    virtual const float getWidth() const = 0;
    virtual const float getHeight() const = 0;
    virtual void set(float x, float y, float w, float h) = 0;
    virtual void set(const Math::Vector2D &v, const Math::Vector2D &s) = 0;
    virtual void set(const Math::Vector2D &v, float r) = 0;
    virtual void moveShape(const Math::Vector2D& v){
        this->position += v;
    }
    virtual const Math::Vector2D& getPosition() const = 0;
    virtual const Math::Vector2D& getSize() const = 0; 
    virtual Shape* clone() = 0;
};
#endif
