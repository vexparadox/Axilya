//
//  Rect.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Rect_h
#define Rect_h

#include "Math.h"
#include "Shape.h"
namespace Graphics{
    class Rect : public Shape{
        float w, h;
    public:
        Rect(const Math::Vector2D &v1, float w, float h): Shape(v1){
            this->w = w;
            this->h = h;
        }
        
        Rect(float x, float y, float w, float h) : Shape(Math::Vector2D(x, y)){
            this->w = w;
            this->h = h;
        }
        
        void set(const Math::Vector2D &v, float w, float h){
            this->set(v.x, v.y, w, h);
        }
       /*
       * A method to set the Rect's parameters
       * @param x a float to set the x value to
       * @param y a float to set the y value to
       * @param w a float to set the width to
       * @param h a float to set the height to
       * @see Rect::set(const Math::Vector2D &v, float w, float h)
       * @return void
       */
        void set(float x, float y, float w, float h){
            this->position.x = x;
            this->position.y = y;
            this->w = w;
            this->h = h;
        }
       /*
       * A method to get the Rect's x position
       * @return const float
       */
        const float getX() const{
            return position.x;
        }
       /*
       * A method to get the Rect's y position
       * @return const float
       */
        const float getY() const{
            return position.y;
        }
       /*
       * A method to get the Rect's width
       * @return const float
       */
        const float getWidth() const{
            return w;
        }
       /*
       * A method to get the Rect's height
       * @return const float
       */
        const float getHeight() const{
            return h;
        }
    };
}

#endif /* Rect_h */
