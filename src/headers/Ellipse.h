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
        /*!
        * The constructor of the Ellipse Shape
        * 
        * @param cp the center point of the Ellipse
        * @param xR the radius of the Ellipse in the x axis
        * @param yR the radius of the Ellipse in the y axis
        */ 
        Ellipse(const Math::Vector2D &cp, float xR, float yR) : Shape(cp, Math::Vector2D(xR, yR)) {}
        /*!
        * The constructor of the Ellipse Shape
        * 
        * @param cp the center point of the Ellipse
        * @param r the radius of the Ellipse
        */ 
        Ellipse(const Math::Vector2D &cp, float r) : Shape(cp, Math::Vector2D(r, r)) {}
        /*!
        * The constructor of the Ellipse Shape
        * 
        * @param x the x position of the center of the Ellipse
        * @param y the y position of the center of the Ellipse
        * @param xR the radius of the Ellipse in the x axis
        * @param yR the radius of the Ellipse in the y axis
        */ 
        Ellipse(float x, float y, float xR, float yR) : Shape(Math::Vector2D(x, y), Math::Vector2D(xR, yR)) {}
        /*!
        * The constructor of the Ellipse Shape
        * 
        * @param x the x position of the center of the Ellipse
        * @param y the y position of the center of the Ellipse
        * @param r the radius of the Ellipse
        */ 
        Ellipse(float x, float y, float r) : Shape(Math::Vector2D(x, y), Math::Vector2D(r, r)) {}
        ~Ellipse() {};
        /*!
        * A method to set the position and size of the Ellipse
        * 
        * @param v a 2D vector that holds the center point of the Ellipse
        * @param s a 2D vector taht holds the size of the Ellipse (x radius, y radius)
        */ 
        void set(const Math::Vector2D &v, const Math::Vector2D &s)
        {
            this->set(v.x, v.y, s.x, s.y);
        }
        /*!
        * A method to set the position and size of the Ellipse
        * 
        * @param v a 2D vector that holds the center point of the Ellipse
        * @param r the radius of the Ellipse
        */ 
        void set(const Math::Vector2D &v, float r)
        {
            this->set(v.x, v.y, r, r);
        }
        /*!
        * A method to set the position and size of the Ellipse
        * 
        * @param x the x position of the center of the Ellipse
        * @param y the y position of the center of the Ellipse
        * @param xR the radius of the Ellipse in the x axis
        * @param yR the radius of the Ellipse in the y axis
        */ 
        void set(float x, float y, float xR, float yR)
        {
            this->position.x = x;
            this->position.y = y;
            this->size.x = xR;
            this->size.y = yR;
        }
        
        /*!
        * A method to get the position of the Ellipse
        * 
        * @return The center position of the Ellipse
        */        
        const Math::Vector2D& getPosition() const{
            return position;
        }
        /*!
        * A method to get the size of the Ellipse
        * 
        * @return The size of the Ellipse (x radius, y radius)
        */ 
        const Math::Vector2D& getSize() const {
            return size;
        }
        /*!
        * A method to get the width of the Ellipse
        * 
        * @return The width of the Ellipse (x radius)
        */ 
        const float getWidth() const{
            return size.x;
        }
        /*!
        * A method to get the height of the Ellipse
        * 
        * @return The height of the Ellipse (y radius)
        */ 
        const float getHeight() const{
            return size.y;
        }
        /*!
        * A method to get to clone this Shape
        * 
        * @return a clone of this Ellipse
        */ 
        Shape* clone(){
            return new Ellipse(this->position, this->size.x, this->size.y);
        }
    };
}

#endif /* Ellipse_h */
