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

#ifndef AXRect_h
#define AXRect_h

#include "AXMath.hpp"
#include "AXShape.h"
  class AXRect : public AXShape{
  public:
      ~AXRect(){};
    /*!
     * The constructor of a AXRect
     * @param x a float to set the x position
     * @param y a float to set the y position
     * @param w a float to set the width to
     * @param h a float to set the height to
     * @see AXShape constructor
     */
      AXRect(float x, float y, float w, float h) : AXShape(AXVector2D(x, y), AXVector2D(w, h)){
      }
    /*!
     * The constructor of a AXRect
     * @param v1 2D vector to set the position
     * @param w a float to set the width to
     * @param h a float to set the height to
     * @see AXShape constructor
     */
      AXRect(const AXVector2D &v1, float w, float h): AXShape(v1, AXVector2D(w, h)){
      }
    /*!
     * The constructor of a AXRect
     * @param v1 2D vector to set the position (x, y)
     * @param size 2D vector to set the size (w, h)
     * @see AXShape constructor
     */
      AXRect(const AXVector2D &v1, const AXVector2D& size): AXShape(v1, size){
      }
     /*!
     * A method to set the AXRect's parameters
     * @param x a float to set the x value to
     * @param y a float to set the y value to
     * @param w a float to set the width to
     * @param h a float to set the height to
     * @see Other AXRect::set methods
     */
      void set(float x, float y, float w, float h){
          this->position.x = x;
          this->position.y = y;
          this->size.x = w;
          this->size.y = h;
      }
     /*!
     * A method to set the AXRect's parameters
     * @param v a 2D vector to set the position (x, y)
     * @param size a 2D vector to set the size (w, h)
     * @see Other AXRect::set methods
     */
      void set(const AXVector2D &v, const AXVector2D &size){
          this->set(v.x, v.y, size.x, size.y);
      }
     /*!
     * A method to set the AXRect's parameters
     * @param v a 2D vector to set the position (x, y)
     * @param r a float to set both the width and height
     * @see Other AXRect::set methods
     */
      void set(const AXVector2D &v, float r){
          this->set(v.x, v.y, r, r);
      }

      /*!
     * A method to get the AXRect's position
     */
      const AXVector2D& getPosition() const{
          return position;
      }
      /*!
     * A method to get the AXRect's size
     */
      const AXVector2D& getSize() const{
          return size;
      }
     /*!
     * A method to get the AXRect's x position
     */
      const float getX() const{
          return position.x;
      }
     /*!
     * A method to get the AXRect's y position
     */
      const float getY() const{
          return position.y;
      }
     /*!
     * A method to get the AXRect's width
     */
      const float getWidth() const{
          return size.x;
      }
     /*!
     * A method to get the AXRect's height
     */
      const float getHeight() const{
          return size.y;
      }
     /*!
     * A method that clones the shape
     * @return A clone of this AXRect
     */
      virtual AXShape* clone(){
        return new AXRect(this->position, this->size);
      }
  };
#endif /* Rect_h */
