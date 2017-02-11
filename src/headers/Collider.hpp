#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "Types.h"
class Entity;
class Collider{
public:
    Math::Vector2D center, halfSize;
    Shape* bounds;
    Entity* owner = 0;
    bool screenBound;
    //take the owner and bounds of the collider 
    Collider();
    virtual ~Collider();
    Shape* getBounds();
    void setOwner(Entity* e);
    Entity* getOwner();
    virtual void mouseCheck() = 0;
    virtual int worldCollideCheck(Math::Vector2D&) = 0;
    virtual int checkMovement(Entity*, Math::Vector2D&) = 0;
    virtual Collider* clone() = 0;
};	

#endif