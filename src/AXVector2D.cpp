//
//  AXVector2D.cpp
//  Axilya
//
//  Created by William Meaton on 29/01/2017.
//  Copyright © 2017 William Meaton. All rights reserved.
//

#include "headers/AXVector2D.h"
AXVector2D::AXVector2D(float x, float y){
    this->x = x;
    this->y = y;
}
AXVector2D::AXVector2D(){
    this->x = 0;
    this->y = 0;
}
AXVector2D::~AXVector2D(){}

bool AXVector2D::operator==(const AXVector2D& other) const{
    return (this->x == other.x && this->y == other.y);
}

bool AXVector2D::operator!=(const AXVector2D& other) const{
    return !(*this == other);
}

bool AXVector2D::operator> (const AXVector2D& other) const{
    return (this->x > other.x && this->y > other.y);
}


bool AXVector2D::operator> (float i){
    return (this->x > i && this->y > i);
}

bool AXVector2D::operator< (const AXVector2D& other){
    return (this->x < other.x && this->y < other.y);
}

bool AXVector2D::operator< (float i){
    return (this->x < i && this->y < i);
}


bool AXVector2D::operator<= (const AXVector2D& v2){
    return (this->x <= v2.x && this->y <= v2.y);
}

bool AXVector2D::operator<= (float i){
    return (this->x <= i && this->y <= i);
}

bool AXVector2D::operator>= (const AXVector2D& v2){
    return (this->x >= v2.x && this->y >= v2.y);
}

bool AXVector2D::operator>= (float i){
    return (this->x >= i && this->y >= i);
}
void AXVector2D::operator+= (const AXVector2D& other){
    (*this) = (*this)+other;
    return;
}

void AXVector2D::operator-= (const AXVector2D& other){
    (*this) = (*this)-other;
    return;
}

AXVector2D AXVector2D::operator+ (const AXVector2D& v) const{
    AXVector2D result;
    result.x = this->x+v.x;
    result.y = this->y+v.y;
    return result;
}

AXVector2D AXVector2D::operator+ (const float& f) const{
    AXVector2D result;
    result.x = this->x+f;
    result.y = this->y+f;
    return result;
}

AXVector2D& AXVector2D::operator= (const AXVector2D& v){
    this->x = v.x;
    this->y = v.y;
    return *this;
}

AXVector2D AXVector2D::operator* (const AXVector2D& v) const{
    AXVector2D result;
    result.x = this->x*v.x;
    result.y = this->y*v.y;
    return result;
}

AXVector2D AXVector2D::operator*(const float& n) const{
    AXVector2D result;
    result.x = this->x*n;
    result.y = this->y*n;
    return result;
}

void AXVector2D::operator*= (const AXVector2D& other){
    (*this) = (*this)*other;
    return;
}

AXVector2D AXVector2D::operator- (const AXVector2D& v) const {
    AXVector2D result;
    result.x = this->x-v.x;
    result.y = this->y-v.y;
    return result;
}

AXVector2D AXVector2D::operator- (const float& f) const {
    AXVector2D result;
    result.x = this->x-f;
    result.y = this->y-f;
    return result;
}

AXVector2D AXVector2D::operator/ (const AXVector2D& v) const{
    AXVector2D result;
    result.x = this->x/v.x;
    result.y = this->y/v.y;
    return result;
}

AXVector2D AXVector2D::operator/ (float n) const{
    AXVector2D result;
    result.x = this->x/n;
    result.y = this->y/n;
    return result;
}

void AXVector2D::operator/= (const AXVector2D& other){
    (*this) = (*this)/other;
    return;
}


void AXVector2D::zero(){
    this->x = 0;
    this->y = 0;
}

float AXVector2D::dot(const AXVector2D& v) const{
    return (this->x*v.x)+(this->y*v.y);
}

//normalise
AXVector2D& AXVector2D::normalise(){
    float length = this->magnitude();
    if(length > 0) {
        this->x/= length;
        this->y/= length;
    }
    return *this;
}

float AXVector2D::magnitude() const{
    return sqrt(x*x+y*y);
}
