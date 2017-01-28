//
//  Vector2D.h
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h
#include <cmath>
#include <iostream>

namespace Math {
    class Vector2D{
    public:
        float x, y;
        Vector2D(float x, float y){
            this->x = x;
            this->y = y;
        }
        Vector2D(){ x = 0; y = 0;}
        ~Vector2D(){}
        inline friend bool operator== (const Vector2D& v1, const Vector2D& v2){
            return (v1.x == v2.x && v1.y == v2.y);
        }
        
        inline friend bool operator!= (const Vector2D& v1, const Vector2D& v2){
            return !(v1 == v2);
        }

        inline friend bool operator> (const Vector2D& v1, const Vector2D& v2){
            return (v1.x > v2.x && v1.y > v2.y);
        }

        inline friend bool operator> (const Vector2D& v1, float i){
            return (v1.x > i && v1.y > i);
        }

        inline friend bool operator< (const Vector2D& v1, const Vector2D& v2){
            return (v1.x < v2.x && v1.y < v2.y);
        }

        inline friend bool operator< (const Vector2D& v1, float i){
            return (v1.x < i && v1.y < i);
        }


        inline friend bool operator<= (const Vector2D& v1, const Vector2D& v2){
            return (v1.x <= v2.x && v1.y <= v2.y);
        }
 
        inline friend bool operator<= (const Vector2D& v1, float i){
            return (v1.x <= i && v1.y <= i);
        }

        inline friend bool operator>= (const Vector2D& v1, const Vector2D& v2){
            return (v1.x >= v2.x && v1.y >= v2.y);
        }

        inline friend bool operator>= (const Vector2D& v1, float i){
            return (v1.x >= i && v1.y >= i);
        }
        
        inline friend void operator+= (Vector2D& v1, const Vector2D& v2){
            v1 = v1+v2;
            return;
        }

        inline friend void operator-= (Vector2D& v1, const Vector2D& v2){
            v1 = v1-v2;
            return;
        }
        
        inline Vector2D operator+ (const Vector2D& v) const{
            Vector2D result;
            result.x = this->x+v.x;
            result.y = this->y+v.y;
            return result;
        }
        
        inline Vector2D operator+ (const float& f) const{
            Vector2D result;
            result.x = this->x+f;
            result.y = this->y+f;
            return result;
        }
        
        inline Vector2D& operator= (const Vector2D& v){
            this->x = v.x;
            this->y = v.y;
            return *this;
        }
        
        inline Vector2D operator* (const Vector2D& v) const{
            Vector2D result;
            result.x = this->x*v.x;
            result.y = this->y*v.y;
            return result;
        }
        
        inline Vector2D operator*(const float& n) const{
            Vector2D result;
            result.x = this->x*n;
            result.y = this->y*n;
            return result;
        }
        
        inline friend void operator*= (Vector2D& v1, const Vector2D& v2){
            v1 = v1*v2;
            return;
        }
        
        inline Vector2D operator- (const Vector2D& v) const {
            Vector2D result;
            result.x = this->x-v.x;
            result.y = this->y-v.y;
            return result;
        }
        
        inline Vector2D operator- (const float& f) const {
            Vector2D result;
            result.x = this->x-f;
            result.y = this->y-f;
            return result;
        }
        
        inline Vector2D operator/ (const Vector2D& v) const{
            Vector2D result;
            result.x = this->x/v.x;
            result.y = this->y/v.y;
            return result;
        }
        
        inline Vector2D operator/ (float n) const{
            Vector2D result;
            result.x = this->x/n;
            result.y = this->y/n;
            return result;
        }
        
        friend inline void operator/= (Vector2D& v1, const Vector2D& v2){
            v1 = v1/v2;
            return;
        }
    	//Zeros the vector
    	inline void zero(){
    	    this->x = 0;
    	    this->y = 0;
    	}		

        inline float dot(const Vector2D& v) const{
            return (this->x*v.x)+(this->y*v.y);
        }

        //normalise
        inline Vector2D& normalise(){
            float length = this->magnitude();
                if(length > 0) {
                    this->x/= length;
                    this->y/= length;
                }
          return *this;
        }

        inline float magnitude() const{
            return sqrt(x*x+y*y);
        }

    };
}
#endif /* Vector2D_h */
