//
//  Transform.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform(const Math::Vector2D& pos, const Math::Vector2D& size): position(pos), size(size){
    
}

Transform::Transform(float x, float y, float w, float h) : position(x, y), size(w, h){
    
}

void Transform::set(const Math::Vector2D &v, const Math::Vector2D &s){
    this->position = v;
    this->size = s;
}

void Transform::set(const Math::Vector2D &v){
    this->position = v;
}

void Transform::set(float x, float y){
    this->position.x = x;
    this->position.y = y;
}

void Transform::moveTransform(const Math::Vector2D &v){
    this->position+v;
}

Math::Vector2D& Transform::getPos(){
    return position;
}

Math::Vector2D& Transform::getSize(){
    return size;
}