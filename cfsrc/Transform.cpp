//
//  Transform.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform(const Math::Vector2D& pos, Entity* owner): Component(owner), position(pos){
    
}

Math::Vector2D& Transform::getPos(){
    return position;
}