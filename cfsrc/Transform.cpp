//
//  Transform.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform(const Math::Vector2D& pos, const Math::Vector2D& size, Entity* owner): Component(owner), position(pos), size(size){
    
}

Transform::Transform(float x, float y, float w, float h, Entity* owner) : Component(owner), position(x, y), size(w, h){
    
}

Math::Vector2D& Transform::getPos(){
    return position;
}

Math::Vector2D& Transform::getSize(){
    return size;
}