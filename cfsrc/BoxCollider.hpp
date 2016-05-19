#ifndef BoxCollider_h
#define BoxCollider_h

#include "Collider.hpp"

class Entity;
class BoxCollider : public Collider{
public:
    BoxCollider(Entity* owner);
    bool collideCheck();
};

#endif