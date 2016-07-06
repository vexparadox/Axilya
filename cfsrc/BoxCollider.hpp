#ifndef BoxCollider_h
#define BoxCollider_h

#include "Collider.hpp"
#include "Runner.hpp"
class Entity;
class BoxCollider : public Collider{
public:
    BoxCollider();
    //checks and corrects against the world boundries
    void worldCollideCheck(Math::Vector2D& v);
    //checks and corrects against collision with this Collider's owner and another collider  
    void collisionColliderCheck(Collider* c);
    //the methods that corrects
    void correctColliderCollision(Collider* c, const Math::Vector2D &v, bool isMoving);
};

#endif