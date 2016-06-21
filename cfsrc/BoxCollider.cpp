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
    //if it goes out of the screen downwards
    if(position.y+size.y+v.y >= screenHeight){
        v.y = 0;
        position.y = screenHeight-size.y;
    }
    //if it goes out of the screen upwards
    if(position.y+v.y < 0){
        v.y = 0;
        position.y = 0;
    }
    //if it goes out of the screen rightways
    if(position.x+size.x+v.x >= screenWidth){
        v.x = 0;
        position.x = screenWidth-size.x;
    }
    //if it goes out of the screen leftways
    if(position.x+v.x < 0){
        v.x = 0;
        position.x = 0;
    }
    //set the players position to the corrected (NEEDS OFFSETS FOR COLLIDERS)
    owner->getTransform()->set(position);
    //Moves the collider to the corrected (NEEDS OFFSETS TOO)
    this->bounds->set(position.x, position.y, size.x, size.y);
}

void BoxCollider::collisionColliderCheck(Collider* c){
    if(!c){
        return;
    }
    Shape* otherBounds = c->getBounds();
    //collide on top left 
    if(otherBounds->getPosition().x > bounds->getPosition().x && otherBounds->getPosition().x < bounds->getPosition().x+bounds->getSize().x){
        if(otherBounds->getPosition().y > bounds->getPosition().y && otherBounds->getPosition().y < bounds->getPosition().y+bounds->getSize().y){
            std::cout << "Top left" << std::endl;
        }
    }
    //collide on top right
    if(otherBounds->getPosition().x+otherBounds->getSize().x > bounds->getPosition().x && otherBounds->getPosition().x+otherBounds->getSize().x < bounds->getPosition().x+bounds->getSize().x){
        if(otherBounds->getPosition().y > bounds->getPosition().y && otherBounds->getPosition().y < bounds->getPosition().y+bounds->getSize().y){
            std::cout << "top right" << std::endl;
        }
    }
    //collide on bottom left
    if(otherBounds->getPosition().x > bounds->getPosition().x && otherBounds->getPosition().x < bounds->getPosition().x+bounds->getSize().x){
        if(otherBounds->getPosition().y+otherBounds->getSize().y > bounds->getPosition().y && otherBounds->getPosition().y+otherBounds->getSize().y < bounds->getPosition().y+bounds->getSize().y){
            std::cout << "Bottom left" << std::endl;
        }
    }
    //collide on bottom right
    if(otherBounds->getPosition().x+otherBounds->getSize().x > bounds->getPosition().x && otherBounds->getPosition().x+otherBounds->getSize().x < bounds->getPosition().x+bounds->getSize().x){
        if(otherBounds->getPosition().y+otherBounds->getSize().y > bounds->getPosition().y && otherBounds->getPosition().y+otherBounds->getSize().y < bounds->getPosition().y+bounds->getSize().y){
            std::cout << "Bottom right" << std::endl;
        }
    }
    

}