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
protected:
    Entity* owner;
    Component();
public:  
    virtual ~Component();
    //change what entity owns this component
    Entity* getOwner();
    //returns what entity owns this component
    void setOwner(Entity*);
    //a virutal update method that Component's can use
    virtual void update(){};
    virtual void onCollision(Entity* e){};
};

#endif /* Component_hpp */
