#include "BoxCollider.hpp"
#include "Entity.hpp"

BoxCollider::BoxCollider(Entity* owner) : Collider(owner){
    
}

void BoxCollider::collideCheck(Math::Vector2D& v){
    Math::Vector2D newPos = owner->getTransform()->getPos();
    Math::Vector2D size = owner->getTransform()->getSize();
    int screenWidth = Runner::getWidth();
    int screenHeight = Runner::getHeight();
    if(newPos.y+size.y+v.y >= screenHeight){
        v.y = 0;
        newPos.y = screenHeight-size.y;
    }
    if(newPos.y+v.y < 0){
        v.y = 0;
        newPos.y = 0;
    }
    if(newPos.x+size.x+v.x >= screenWidth){
        v.x = 0;
        newPos.x = screenWidth-size.x;
    }
    if(newPos.x+v.x < 0){
        v.x = 0;
        newPos.x = 0;
    }
    
    owner->getTransform()->getPos() = newPos;
}