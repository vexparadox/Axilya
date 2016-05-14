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

class Transform : public Component{
    Math::Vector2D position;
public:
    Transform();
    Transform(const Math::Vector2D& pos);
    Math::Vector2D& getPos();
};
#endif /* Transform_hpp */
