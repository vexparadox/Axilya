//
//  Component.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include "Math.h"

class Entity;
class Component{
    Entity* owner;
protected:  
    Entity* getOwner();
    Component(Entity* owner);
    virtual void update(){};
};

#endif /* Component_hpp */
