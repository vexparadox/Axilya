#include "BoxCollider.hpp"
#include "Entity.hpp"

BoxCollider::BoxCollider(Entity* owner) : Collider(owner){
    //create a bounds with the position and size of the entity
    bounds = new Graphics::Rect(owner->getTransform()->getPos(), owner->getTransform()->getSize());
}

void BoxCollider::worldCollideCheck(Math::Vector2D& v){
    //get the bounds
    Math::Vector2D position = bounds->getPosition();
    Math::Vector2D size = Math::Vector2D(bounds->getSize());
    //get the offset between the collider and the entity
    float xOffset = position.x - owner->getTransform()->getPos().x;
    float yOffset = position.y - owner->getTransform()->getPos().y;
    int screenWidth = Runner::getWidth();
    int screenHeight = Runner::getHeight();
    if(position.y+size.y+v.y >= screenHeight){
        v.y = 0;
        position.y = screenHeight-size.y;
    }
    if(position.y+v.y < 0){
        v.y = 0;
        position.y = 0;
    }
    if(position.x+size.x+v.x >= screenWidth){
        v.x = 0;
        position.x = screenWidth-size.x;
    }
    if(position.x+v.x < 0){
        v.x = 0;
        position.x = 0;
    }
    owner->getTransform()->getPos() = position;
    this->bounds->set(position.x, position.y, size.x, size.y);
}

void BoxCollider::collisionEntityCheck(Entity* e){
    if(!e){
        return;
    }
    Shape* otherBounds = e->getCollider()->getBounds();
    
}