//
//  Vector2D.cpp
//  Axilya
//
//  Created by William Meaton on 29/01/2017.
//  Copyright © 2017 William Meaton. All rights reserved.
//

#include "headers/Vector2D.h"
namespace Math{
    Vector2D::Vector2D(float x, float y){
        this->x = x;
        this->y = y;
    }
    Vector2D::Vector2D(){
        this->x = 0;
        this->y = 0;
    }
    Vector2D::~Vector2D(){}
    
    bool Vector2D::operator==(const Vector2D& other) const{
        return (this->x == other.x && this->y == other.y);
    }
    
    bool Vector2D::operator!=(const Vector2D& other) const{
        return !(*this == other);
    }
    
    bool Vector2D::operator> (const Vector2D& other) const{
        return (this->x > other.x && this->y > other.y);
    }
    
    
    bool Vector2D::operator> (float i){
        return (this->x > i && this->y > i);
    }
    
    bool Vector2D::operator< (const Vector2D& other){
        return (this->x < other.x && this->y < other.y);
    }
    
    bool Vector2D::operator< (float i){
        return (this->x < i && this->y < i);
    }
    
    
    bool Vector2D::operator<= (const Vector2D& v2){
        return (this->x <= v2.x && this->y <= v2.y);
    }
    
    bool Vector2D::operator<= (float i){
        return (this->x <= i && this->y <= i);
    }
    
    bool Vector2D::operator>= (const Vector2D& v2){
        return (this->x >= v2.x && this->y >= v2.y);
    }
    
    bool Vector2D::operator>= (float i){
        return (this->x >= i && this->y >= i);
    }
    void Vector2D::operator+= (const Vector2D& other){
        (*this) = (*this)+other;
        return;
    }
    
    void Vector2D::operator-= (const Vector2D& other){
        (*this) = (*this)-other;
        return;
    }
    
    Vector2D Vector2D::operator+ (const Vector2D& v) const{
        Vector2D result;
        result.x = this->x+v.x;
        result.y = this->y+v.y;
        return result;
    }
    
    Vector2D Vector2D::operator+ (const float& f) const{
        Vector2D result;
        result.x = this->x+f;
        result.y = this->y+f;
        return result;
    }
    
    Vector2D& Vector2D::operator= (const Vector2D& v){
        this->x = v.x;
        this->y = v.y;
        return *this;
    }
    
    Vector2D Vector2D::operator* (const Vector2D& v) const{
        Vector2D result;
        result.x = this->x*v.x;
        result.y = this->y*v.y;
        return result;
    }
    
    Vector2D Vector2D::operator*(const float& n) const{
        Vector2D result;
        result.x = this->x*n;
        result.y = this->y*n;
        return result;
    }
    
    void Vector2D::operator*= (const Vector2D& other){
        (*this) = (*this)*other;
        return;
    }
    
    Vector2D Vector2D::operator- (const Vector2D& v) const {
        Vector2D result;
        result.x = this->x-v.x;
        result.y = this->y-v.y;
        return result;
    }
    
    Vector2D Vector2D::operator- (const float& f) const {
        Vector2D result;
        result.x = this->x-f;
        result.y = this->y-f;
        return result;
    }
    
    Vector2D Vector2D::operator/ (const Vector2D& v) const{
        Vector2D result;
        result.x = this->x/v.x;
        result.y = this->y/v.y;
        return result;
    }
    
    Vector2D Vector2D::operator/ (float n) const{
        Vector2D result;
        result.x = this->x/n;
        result.y = this->y/n;
        return result;
    }
    
    void Vector2D::operator/= (const Vector2D& other){
        (*this) = (*this)/other;
        return;
    }
    
    
    void Vector2D::zero(){
        this->x = 0;
        this->y = 0;
    }
    
    float Vector2D::dot(const Vector2D& v) const{
        return (this->x*v.x)+(this->y*v.y);
    }
    
    //normalise
    Vector2D& Vector2D::normalise(){
        float length = this->magnitude();
        if(length > 0) {
            this->x/= length;
            this->y/= length;
        }
        return *this;
    }
    
    float Vector2D::magnitude() const{
        return sqrt(x*x+y*y);
    }

}
