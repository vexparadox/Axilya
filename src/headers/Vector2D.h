//
//  Vector2D.h
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h
#include <math.h>
#include <iostream>

namespace Math {
    class Vector2D{
    public:
        float x, y;
        Vector2D(float x, float y);
        Vector2D();
        ~Vector2D();
        bool operator== (const Vector2D&) const;
        bool operator!= (const Vector2D&) const;
        bool operator> (const Vector2D&) const;
        bool operator> (float i);

        bool operator< (const Vector2D& v2);

        bool operator< (float i);


        bool operator<= (const Vector2D& v2);
 
        bool operator<= (float i);

        bool operator>= (const Vector2D& v2);

        bool operator>= (float i);
        
        void operator+= (const Vector2D&);

        void operator-= (const Vector2D&);
        
        Vector2D operator+ (const Vector2D&) const;
        
        Vector2D operator+ (const float&) const;
        
        Vector2D& operator= (const Vector2D&);
        
        Vector2D operator* (const Vector2D&) const;
        
        Vector2D operator*(const float&) const;
        
        void operator*= (const Vector2D&);
        
        Vector2D operator- (const Vector2D&) const ;
        
        Vector2D operator- (const float&) const;
        
        Vector2D operator/ (const Vector2D&) const;
        
        Vector2D operator/ (float n) const;
        
        void operator/= (const Vector2D&);
        void zero();

        float dot(const Vector2D&) const;
        
        //normalise
        Vector2D& normalise();
        float magnitude() const;

    };
}
#endif /* Vector2D_h */
