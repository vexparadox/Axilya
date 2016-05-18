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
            this->position = v;
            this->w = w;
            this->h = h;
        }
        
        void set(float x, float y, float w, float h){
            this->set(Math::Vector2D(x, y), w, h);
        }
        
        const float getX() const{
            return position.x;
        }
        
        const float getY() const{
            return position.y;
        }
        
        const float getWidth() const{
            return w;
        }
        
        const float getHeight() const{
            return h;
        }
    };
}

#endif /* Rect_h */
