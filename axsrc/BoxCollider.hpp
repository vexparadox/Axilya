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
    //called from the scene  
    bool checkMovement(Entity*, Math::Vector2D&);
    bool overlap(Collider* c);
    //the methods that corrects
    void correctColliderCollision(Collider* c, const Math::Vector2D &v, bool isMoving);
    //checks if it's being clicked or hovered
    void mouseCheck();
    Collider* clone();
};

#endif