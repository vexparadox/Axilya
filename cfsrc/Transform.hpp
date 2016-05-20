//
//  Transform.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "Component.hpp"
class Entity;
class Transform : public Component{
    Math::Vector2D position, size;
public:
    Transform(const Math::Vector2D& pos, const Math::Vector2D& size, Entity* owner);
    Transform(float x, float y, float w, float h, Entity* owner);
    Math::Vector2D& getPos();
    Math::Vector2D& getSize();
};
#endif /* Transform_hpp */
