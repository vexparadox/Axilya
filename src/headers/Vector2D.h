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
 * This class describes a 2D vector, it's used throught Axilya.
 */

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
