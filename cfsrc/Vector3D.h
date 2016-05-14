//
//  Vector3D.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
#ifndef Vector3D_h
#define Vector3D_h

//A 3D vector, missing some operators but not really used in my program.
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
