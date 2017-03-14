//
//  AXTransform.cpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/AXTransform.hpp"

AXTransform::AXTransform(const Math::Vector2D& pos, const Math::Vector2D& size): position(pos), size(size){
    
}

AXTransform::AXTransform(float x, float y, float w, float h) : position(x, y), size(w, h){
    
}

void AXTransform::set(float x, float y, float w, float h){
    this->position.x = x;
    this->position.y = y;
    this->size.x = w;
    this->size.y = h;
}

void AXTransform::set(const Math::Vector2D &v, const Math::Vector2D &s){
    this->position = v;
    this->size = s;
}

void AXTransform::set(const Math::Vector2D &v){
    this->position = v;
}

void AXTransform::set(float x, float y){
    this->position.x = x;
    this->position.y = y;
}

void AXTransform::moveTransform(const Math::Vector2D &v){
    this->lastPosition = position;
    this->position += v;
}

Math::Vector2D& AXTransform::getPosition(){
    return position;
}

float AXTransform::getWidth(){
    return this->size.x;
}

float AXTransform::getHeight(){
    return this->size.y;    
}

Math::Vector2D& AXTransform::getSize(){
    return size;
}

AXComponent* AXTransform::clone(){
	return new AXTransform(position, size);
}
