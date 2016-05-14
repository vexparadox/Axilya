//
//  Vector2D.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h
#include <cmath>

//A much more fleshed out 2D vector
namespace Math {
    class Vector2D{
    public:
        float x, y;
        Vector2D(float x, float y){
            this->x = x;
            this->y = y;
        }
        
        //TO ADD: dot, scale, etc
        Vector2D(){}
        ~Vector2D(){}
        inline friend bool operator== (const Vector2D& v1, const Vector2D& v2){
            if(v1.x == v2.x && v1.y == v2.y){
                return true;
            }
            return false;
        }
        
        inline friend bool operator!= (const Vector2D& v1, const Vector2D& v2){
            return !(v1 == v2);
        }
        
        inline friend void operator+= (Vector2D& v1, const Vector2D& v2){
            v1 = v1+v2;
            return;
        }
        
        inline Vector2D& operator+ (const Vector2D& v){
            this->x += v.x;
            this->y += v.y;
            return *this;
        }
        
        inline Vector2D& operator+ (const float& f){
            this->x += f;
            this->y += f;
            return *this;
        }
        
        inline Vector2D& operator= (const Vector2D& v){
            this->x = v.x;
            this->y = v.y;
            return *this;
        }
        
        inline Vector2D& operator* (const Vector2D& v){
            this->x *= v.x;
            this->y *= v.y;
            return *this;
        }
        
        inline Vector2D& operator*(const float& n){
            this->x *= n;
            this->y *= n;
            return *this;
        }
        
        friend inline void operator*= (Vector2D& v1, const Vector2D& v2){
            v1 = v1*v2;
            return;
        }
        
        inline Vector2D& operator- (const Vector2D& v) {
            this->x -= v.x;
            this->y -= v.y;
            return *this;
        }
        
        inline Vector2D& operator- (const float& f){
            this->x -= f;
            this->y -= f;
            return *this;
        }
        
        inline Vector2D& operator/ (const Vector2D& v) {
            this->x /= v.x;
            this->y /= v.y;
            return *this;
        }
        
        inline Vector2D& operator/ (float n){
            this->x /= n;
            this->y /= n;
            return *this;
        }
        
        friend inline void operator/= (Vector2D& v1, const Vector2D& v2){
            v1 = v1/v2;
            return;
        }
            
        //normalise
        inline Vector2D& normalise(){
            float length = this->length();
                if(length > 0) {
                    this->x/= length;
                    this->y/= length;
                }
          return *this;
        }
        
        //Returns the length of a vec using Pythag (A^2+B^2 = C^2)
        float length() const{
            return sqrt(x*x+y*y);
        }

    };
}
#endif /* Vector2D_h */