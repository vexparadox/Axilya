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
 * This class describes a 3D vector, it's used rarely inside of Axilya.
 */
#ifndef Vector3D_h
#define Vector3D_h
namespace Math {
    class Vector3D{
    public:
        float x, y, z;
        Vector3D(float x, float y, float z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        Vector3D(){}
        ~Vector3D(){};
        inline friend bool operator== (const Vector3D& v1, const Vector3D& v2){
            if(v1.x == v2.x && v1.y == v2.y && v1.z == v2.z){
                return true;
            }
            return false;
        }
        
        inline friend bool operator!= (const Vector3D& v1, const Vector3D& v2){
            return !(v1 == v2);
        }
        
        inline friend void operator+= (Vector3D& v1, Vector3D& v2){
            v1.x = v1.x + v2.x;
            v1.y = v1.y + v2.y;
            v1.z = v1.z + v1.z;
            return;
        }
        
        inline Vector3D& operator+ (const Vector3D& v){
            this->x += v.x;
            this->y += v.y;
            this->z += v.z;
            return *this;
        }
        
        inline Vector3D& operator= (const Vector3D& v){
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            return *this;
        }
        
        inline Vector3D& operator*(const Vector3D& v){
            this->x *= v.x;
            this->y *= v.y;
            this->z *= v.z;
            return *this;
        }
        
        inline Vector3D& operator- (const Vector3D& v) {
            this->x -= v.x;
            this->y -= v.y;
            this->z -= v.z;
            return *this;
        }
        
        inline Vector3D& operator/ (const Vector3D& v) {
            this->x /= v.x;
            this->y /= v.y;
            this->z /= v.z;
            return *this;
        }
        
    };
}

#endif /* Vector3D_h */
