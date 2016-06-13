#ifndef BoxCollider_h
#define BoxCollider_h

#include "Collider.hpp"
#include "Runner.hpp"
class Entity;
class BoxCollider : public Collider{
public:
    BoxCollider(Entity* owner);
    //checks and corrects against the world boundries
    virtual void worldCollideCheck(Math::Vector2D& v);
    //checks and corrects against collision with this Collider's owner and an enitity  
    virtual void collisionEntityCheck(Entity* e);
};

#endif