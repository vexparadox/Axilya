#ifndef BoxCollider_h
#define BoxCollider_h

#include "Collider.hpp"
#include "AXWindow.hpp"
#include "CollideDirections.hpp"
class Entity;
class BoxCollider : public Collider{
public:
    BoxCollider();
    //checks and corrects against the world boundries
    int worldCollideCheck(Math::Vector2D& v);
    //checks and corrects against collision with this Collider's owner and another collider
    //called from the scene  
    int checkMovement(Entity*, Math::Vector2D&);
    //checks if it's being clicked or hovered
    void mouseCheck();
    Collider* clone();
};

#endif
