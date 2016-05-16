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
    Math::Vector2D position;
public:
    Transform(const Math::Vector2D& pos, Entity* owner);
    Math::Vector2D& getPos();
};
#endif /* Transform_hpp */
