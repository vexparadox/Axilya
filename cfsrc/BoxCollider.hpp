#ifndef BoxCollider_h
#define BoxCollider_h

#include "Collider.hpp"
#include "Runner.hpp"
class Entity;
class BoxCollider : public Collider{
public:
    BoxCollider(Entity* owner);
    virtual void collideCheck(Math::Vector2D& v);
};

#endif