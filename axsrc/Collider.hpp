#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Types.h"

class Collider : public Component{
    //temporary fix
public:
    Math::Vector2D center, halfSize;
    Shape* bounds;
public:
    //take the owner and bounds of the collider 
    Collider();
    Shape* getBounds();
    virtual void mouseCheck() = 0;
    virtual void worldCollideCheck(Math::Vector2D&) = 0;
    virtual bool checkMovement(Entity*, Math::Vector2D&) = 0;
};

#endif