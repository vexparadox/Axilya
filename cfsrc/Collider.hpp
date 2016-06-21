#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Types.h"

class Collider : public Component{
protected:
    Shape* bounds = 0; 
public:
    //take the owner and bounds of the collider 
    Collider(Entity*);
    Shape* getBounds();
    virtual void worldCollideCheck(Math::Vector2D&) = 0;
    virtual void collisionColliderCheck(Collider* c) = 0;
};

#endif