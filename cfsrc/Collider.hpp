#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Types.h"

class Collider : public Component{
    Shape* bounds; 
protected:
    Vector2D::
public:
    //take the owner and bounds of the collider 
    Collider(Entity*);
    virtual void worldCollideCheck(Math::Vector2D&) = 0;
    virtual void collisionEntityCheck(Entity* e) = 0;
};

#endif