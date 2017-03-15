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
#ifndef AXShape_h
#define AXShape_h
#include "AXVector2D.h"
class AXShape{
protected:
    AXVector2D position, size;
public:
    /*!
    * Constructor of Shapes
    * Rects, Ellipses (and Triangles) are Shapes
    * @param v the center position of the AXShape
    */
    AXShape(const AXVector2D& v, const AXVector2D& size){
        this->position = v;
        this->size = size;
    }
    virtual ~AXShape(){};
    virtual const float getWidth() const = 0;
    virtual const float getHeight() const = 0;
    virtual void set(float x, float y, float w, float h) = 0;
    virtual void set(const AXVector2D &v, const AXVector2D &s) = 0;
    virtual void set(const AXVector2D &v, float r) = 0;
    virtual void moveShape(const AXVector2D& v){
        this->position += v;
    }
    virtual const AXVector2D& getPosition() const = 0;
    virtual const AXVector2D& getSize() const = 0; 
    virtual AXShape* clone() = 0;
};
#endif
