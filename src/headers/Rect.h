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
 * This class describes a rectangluar shape.
 */

#ifndef Rect_h
#define Rect_h

#include "Math.h"
#include "Shape.h"
namespace AXGraphics{
    class Rect : public Shape{
    public:
        ~Rect(){};
      /*!
       * The constructor of a Rect
       * @param x a float to set the x position
       * @param y a float to set the y position
       * @param w a float to set the width to
       * @param h a float to set the height to
       * @see Shape constructor
       */
        Rect(float x, float y, float w, float h) : Shape(Math::Vector2D(x, y), Math::Vector2D(w, h)){
        }
      /*!
       * The constructor of a Rect
       * @param v1 2D vector to set the position
       * @param w a float to set the width to
       * @param h a float to set the height to
       * @see Shape constructor
       */
        Rect(const Math::Vector2D &v1, float w, float h): Shape(v1, Math::Vector2D(w, h)){
        }
      /*!
       * The constructor of a Rect
       * @param v1 2D vector to set the position (x, y)
       * @param size 2D vector to set the size (w, h)
       * @see Shape constructor
       */
        Rect(const Math::Vector2D &v1, const Math::Vector2D& size): Shape(v1, size){
        }
       /*!
       * A method to set the Rect's parameters
       * @param x a float to set the x value to
       * @param y a float to set the y value to
       * @param w a float to set the width to
       * @param h a float to set the height to
       * @see Other Rect::set methods
       */
        void set(float x, float y, float w, float h){
            this->position.x = x;
            this->position.y = y;
            this->size.x = w;
            this->size.y = h;
        }
       /*!
       * A method to set the Rect's parameters
       * @param v a 2D vector to set the position (x, y)
       * @param size a 2D vector to set the size (w, h)
       * @see Other Rect::set methods
       */
        void set(const Math::Vector2D &v, const Math::Vector2D &size){
            this->set(v.x, v.y, size.x, size.y);
        }
       /*!
       * A method to set the Rect's parameters
       * @param v a 2D vector to set the position (x, y)
       * @param r a float to set both the width and height
       * @see Other Rect::set methods
       */
        void set(const Math::Vector2D &v, float r){
            this->set(v.x, v.y, r, r);
        }

        /*!
       * A method to get the Rect's position
       */
        const Math::Vector2D& getPosition() const{
            return position;
        }
        /*!
       * A method to get the Rect's size
       */
        const Math::Vector2D& getSize() const{
            return size;
        }
       /*!
       * A method to get the Rect's x position
       */
        const float getX() const{
            return position.x;
        }
       /*!
       * A method to get the Rect's y position
       */
        const float getY() const{
            return position.y;
        }
       /*!
       * A method to get the Rect's width
       */
        const float getWidth() const{
            return size.x;
        }
       /*!
       * A method to get the Rect's height
       */
        const float getHeight() const{
            return size.y;
        }
       /*!
       * A method that clones the shape
       * @return A clone of this Rect
       */
        virtual Shape* clone(){
          return new Rect(this->position, this->size);
        }
    };
}
#endif /* Rect_h */
