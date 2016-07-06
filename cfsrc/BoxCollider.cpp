#include "BoxCollider.hpp"
#include "Entity.hpp"

BoxCollider::BoxCollider(){
}

void BoxCollider::worldCollideCheck(Math::Vector2D& v){
    //get the bounds
    Math::Vector2D position = bounds->getPosition();
    Math::Vector2D size = bounds->getSize();
    //get the offset between the collider and the entity
    float xOffset = position.x - owner->getTransform()->getPos().x;
    float yOffset = position.y - owner->getTransform()->getPos().y;
    int screenWidth = Runner::getWidth();
    int screenHeight = Runner::getHeight();
    //if it goes out of the screen downwards
    if(position.y+size.y+v.y >= screenHeight){
        v.y = 0;
        position.y = screenHeight - size.y;
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

bool BoxCollider::overlap(Collider* c)
{
    Shape* other = c->getBounds();
    return !(other->getPosition().x > bounds->getPosition().x+bounds->getSize().x
        || other->getPosition().x+other->getSize().x < bounds->getPosition().x
        || other->getPosition().y > bounds->getPosition().y+bounds->getSize().y
        || other->getPosition().y+other->getSize().y < bounds->getPosition().y);


    // return (Math::absolute(bounds->getPosition().x - other->getPosition().x) * 2 < (bounds->getSize().x + other->getSize().x)) &&
        //  (Math::absolute(bounds->getPosition().y - other->getPosition().y) * 2 < (bounds->getSize().y + other->getSize().y));
}

void BoxCollider::collisionColliderCheck(Collider* c){
    if(!c){
        return;
    }
    bool collision = false;
    bool isMoving = owner->getRigidBody()->isMoving();
    if(isMoving){
        if(overlap(c)){
            std::cout << c->getBounds()->getPosition().x << c->getBounds()->getPosition().y << std::endl;
            collision = true;
            std::cout << "Collision" << std::endl;
            owner->getRigidBody()->setForce(0,0);
        }
    }
    // //bounds for THIS colliders Shape
    // Math::Vector2D bottomRightBound = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y + bounds->getSize().y);
    // Math::Vector2D topLeftBound = bounds->getPosition();
    // Math::Vector2D bottomLeftBound = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y + bounds->getSize().y);
    // Math::Vector2D topRightBound = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y);

    // //collide on the top left
    // Math::Vector2D topLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y);
    // if(Math::isInsideQuad(topLeft, topLeftBound, bottomRightBound)){
    //     float xOffset = bounds->getPosition().x - bottomRightBound.x;
    //     float yOffset = bounds->getPosition().y - bottomRightBound.y;
    //     if(xOffset > yOffset){
    //         owner->getTransform()->set(bottomRightBound.x, bounds->getPosition().y);
    //     }else if(yOffset < xOffset){
    //         owner->getTransform()->set(bounds->getPosition().y, bottomRightBound.y);
    //     }else{
    //         owner->getTransform()->set(bottomRightBound.x, bottomRightBound.y);
    //     }
    //     owner->getRigidBody()->setForce(0, 0);
    // }
    
    // //collide on the top right
    // Math::Vector2D topRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y);
    // if(Math::isInsideQuad(topRight, topLeftBound, bottomRightBound)){
    //     std::cout << "top right" << std::endl;
    //     float xOffset = bounds->getPosition().x - bottomLeftBound.x;
    //     float yOffset = bounds->getPosition().y - bottomLeftBound.y;
    //     if(xOffset > yOffset){
    //         owner->getTransform()->set(bottomLeftBound.x, bounds->getPosition().y);
    //     }else if(yOffset < xOffset){
    //         owner->getTransform()->set(bounds->getPosition().y, bottomLeftBound.y);
    //     }else{
    //         owner->getTransform()->set(bottomLeftBound.x, bottomLeftBound.y);
    //     }
    //     owner->getRigidBody()->setForce(0, 0);
    // }

    // //collide on the bottom left
    // Math::Vector2D bottomLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y+otherBounds->getSize().y);
    // if(Math::isInsideQuad(bottomLeft, topLeftBound, bottomRightBound)){
    //     std::cout << "Bottom left" << std::endl;
    //     float xOffset = bounds->getPosition().x - topRightBound.x;
    //     float yOffset = bounds->getPosition().y - topRightBound.y;
    //     if(xOffset > yOffset){
    //         owner->getTransform()->set(topRightBound.x, bounds->getPosition().y);
    //     }else if(yOffset < xOffset){
    //         owner->getTransform()->set(bounds->getPosition().y, topRightBound.y);
    //     }else{
    //         owner->getTransform()->set(topRightBound.x, topRightBound.y);
    //     }
    //     owner->getRigidBody()->setForce(0, 0);
    // }

    // //collide on bottom right
    // Math::Vector2D bottomRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y);
    // if(Math::isInsideQuad(bottomRight, topLeftBound, bottomRightBound)){
    //     std::cout << "Bottom right" << std::endl;
    //     float xOffset = bounds->getPosition().x - topLeftBound.x;
    //     float yOffset = bounds->getPosition().y - topLeftBound.y;
    //     if(xOffset > yOffset){
    //         owner->getTransform()->set(topLeftBound.x, bounds->getPosition().y);
    //     }else if(yOffset < xOffset){
    //         owner->getTransform()->set(bounds->getPosition().y, topLeftBound.y);
    //     }else{
    //         owner->getTransform()->set(topLeftBound.x, topLeftBound.y);
    //     }
    //     owner->getRigidBody()->setForce(0, 0);
    // }   
    // //if there has been some collide, tell the entity 
    if(collision){
        //call collisions on the entities
        c->getOwner()->onCollision(owner);
        owner->onCollision(c->getOwner());
    }
}

void BoxCollider::correctColliderCollision(Collider *c, const Math::Vector2D& v, bool isMoving){
    if(isMoving){
        owner->getTransform()->set(v.x, v.y);
        owner->getRigidBody()->setForce(0, 0);
    }else{
        c->getOwner()->getTransform()->set(v.x, v.y);
        c->getOwner()->getRigidBody()->setForce(0, 0);
    }
}