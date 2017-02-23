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
 * This class describes an ellipse shape.
 */
#ifndef Ellipse_h
#define Ellipse_h
#include "Vector2D.h"
#include "Shape.h"

namespace AXGraphics{
    class Ellipse : public Shape{
    private:
        //x radius and y radius
        float xR, yR;
    public:

        Ellipse(const Math::Vector2D &cp, float xR, float yR) : Shape(cp, Math::Vector2D(xR, yR))
        {
        }
        Ellipse(const Math::Vector2D &cp, float r) : Shape(cp, Math::Vector2D(r, r))
        {   
        }
        Ellipse(float x, float y, float xR, float yR) : Shape(Math::Vector2D(x, y), Math::Vector2D(xR, yR))
        {
        }
        Ellipse(float x, float y, float r) : Shape(Math::Vector2D(x, y), Math::Vector2D(r, r))
        {
        }
        ~Ellipse(){};
        
        void set(const Math::Vector2D &v, const Math::Vector2D &s)
        {
            this->set(v.x, v.y, s.x, s.y);
        }
        
        void set(const Math::Vector2D &v, float r)
        {
            this->set(v.x, v.y, r, r);
        }
        
        void set(float x, float y, float xR, float yR)
        {
            this->position.x = x;
            this->position.y = y;
            this->size.x = xR;
            this->size.y = yR;
        }

        //Getters
        Math::Vector2D getVec() const { return  position;};
        
        const Math::Vector2D& getPosition() const{
            return position;
        }
        const Math::Vector2D& getSize() const {
            return size;
        }
        const float getWidth() const{
            return size.x;
        }
        const float getHeight() const{
            return size.y;
        }
        Shape* clone(){
            return new Ellipse(this->position, this->size.x, this->size.y);
        }
    };
}

#endif /* Ellipse_h */
