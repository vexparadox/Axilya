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
    return false;
//     return !(other->getPosition().x > bounds->getPosition().x+bounds->getSize().x
//         || other->getPosition().x+other->getSize().x < bounds->getPosition().x
//         || other->getPosition().y > bounds->getPosition().y+bounds->getSize().y
//         || other->getPosition().y+other->getSize().y < bounds->getPosition().y);
}

bool BoxCollider::checkMovement(Entity* e, Math::Vector2D& proposedMovement){
    Shape* other = e->getCollider()->getBounds();
    Math::Vector2D tempPosition = proposedMovement;
    bool oP = !(tempPosition.x > bounds->getPosition().x+bounds->getSize().x
        || tempPosition.x+other->getSize().x < bounds->getPosition().x
        || tempPosition.y > bounds->getPosition().y+bounds->getSize().y
        || tempPosition.y+other->getSize().y < bounds->getPosition().y);

    if(oP){
            Shape* oBounds = e->getCollider()->getBounds();
            float x = tempPosition.x, y = tempPosition.y;
            if(bounds->getPosition().x+bounds->getSize().x < tempPosition.x){
                x = tempPosition.x-bounds->getSize().x;
            } else if(bounds->getPosition().x > tempPosition.x+oBounds->getSize().x){
                x = tempPosition.x;
            }
            if(bounds->getPosition().y+bounds->getSize().y < tempPosition.y){
                y = tempPosition.y-oBounds->getSize().y;
            } else if(bounds->getPosition().y > tempPosition.y+oBounds->getSize().y){
                y = tempPosition.y+oBounds->getSize().y;
            }
            tempPosition.x = x;
            tempPosition.y = y;
            proposedMovement = tempPosition;
            std::cout << "Proposed " << tempPosition.x  << " "<< tempPosition.y << std::endl;
        return true;
    }
    return false;
}

// void BoxCollider::collisionColliderCheck(Collider* c){
//     if(!c){
//         return;
//     }
//     Shape* oBounds = c->getBounds();
//     bool collision = false;
//     bool isMoving = owner->getRigidBody()->isMoving();
//     if(isMoving){
//         if(overlap(c)){
//             collision = true;
//             float x, y;
//             if(owner->getRigidBody()->getForce().x < 0){
//                 x = 1; 
//             }else{
//                 x = -1;
//             }
//             if(owner->getRigidBody()->getForce().y < 0){
//                 y = -1; 
//             }else{
//                 y = 1;
//             }
//             owner->getRigidBody()->setForce(x, 0);
//         }
//     }
//     // //bounds for THIS colliders Shape
//     // Math::Vector2D bottomRightBound = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y + bounds->getSize().y);
//     // Math::Vector2D topLeftBound = bounds->getPosition();
//     // Math::Vector2D bottomLeftBound = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y + bounds->getSize().y);
//     // Math::Vector2D topRightBound = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y);

//     // //collide on the top left
//     // Math::Vector2D topLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y);
//     // if(Math::isInsideQuad(topLeft, topLeftBound, bottomRightBound)){
//     //     float xOffset = bounds->getPosition().x - bottomRightBound.x;
//     //     float yOffset = bounds->getPosition().y - bottomRightBound.y;
//     //     if(xOffset > yOffset){
//     //         owner->getTransform()->set(bottomRightBound.x, bounds->getPosition().y);
//     //     }else if(yOffset < xOffset){
//     //         owner->getTransform()->set(bounds->getPosition().y, bottomRightBound.y);
//     //     }else{
//     //         owner->getTransform()->set(bottomRightBound.x, bottomRightBound.y);
//     //     }
//     //     owner->getRigidBody()->setForce(0, 0);
//     // }
    
//     // //collide on the top right
//     // Math::Vector2D topRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y);
//     // if(Math::isInsideQuad(topRight, topLeftBound, bottomRightBound)){
//     //     std::cout << "top right" << std::endl;
//     //     float xOffset = bounds->getPosition().x - bottomLeftBound.x;
//     //     float yOffset = bounds->getPosition().y - bottomLeftBound.y;
//     //     if(xOffset > yOffset){
//     //         owner->getTransform()->set(bottomLeftBound.x, bounds->getPosition().y);
//     //     }else if(yOffset < xOffset){
//     //         owner->getTransform()->set(bounds->getPosition().y, bottomLeftBound.y);
//     //     }else{
//     //         owner->getTransform()->set(bottomLeftBound.x, bottomLeftBound.y);
//     //     }
//     //     owner->getRigidBody()->setForce(0, 0);
//     // }

//     // //collide on the bottom left
//     // Math::Vector2D bottomLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y+otherBounds->getSize().y);
//     // if(Math::isInsideQuad(bottomLeft, topLeftBound, bottomRightBound)){
//     //     std::cout << "Bottom left" << std::endl;
//     //     float xOffset = bounds->getPosition().x - topRightBound.x;
//     //     float yOffset = bounds->getPosition().y - topRightBound.y;
//     //     if(xOffset > yOffset){
//     //         owner->getTransform()->set(topRightBound.x, bounds->getPosition().y);
//     //     }else if(yOffset < xOffset){
//     //         owner->getTransform()->set(bounds->getPosition().y, topRightBound.y);
//     //     }else{
//     //         owner->getTransform()->set(topRightBound.x, topRightBound.y);
//     //     }
//     //     owner->getRigidBody()->setForce(0, 0);
//     // }

//     // //collide on bottom right
//     // Math::Vector2D bottomRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y);
//     // if(Math::isInsideQuad(bottomRight, topLeftBound, bottomRightBound)){
//     //     std::cout << "Bottom right" << std::endl;
//     //     float xOffset = bounds->getPosition().x - topLeftBound.x;
//     //     float yOffset = bounds->getPosition().y - topLeftBound.y;
//     //     if(xOffset > yOffset){
//     //         owner->getTransform()->set(topLeftBound.x, bounds->getPosition().y);
//     //     }else if(yOffset < xOffset){
//     //         owner->getTransform()->set(bounds->getPosition().y, topLeftBound.y);
//     //     }else{
//     //         owner->getTransform()->set(topLeftBound.x, topLeftBound.y);
//     //     }
//     //     owner->getRigidBody()->setForce(0, 0);
//     // }   
//     // //if there has been some collide, tell the entity 
//     if(collision){
//         //call collisions on the entities
//         c->getOwner()->onCollision(owner);
//         owner->onCollision(c->getOwner());
//     }
// }

void BoxCollider::correctColliderCollision(Collider *c, const Math::Vector2D& v, bool isMoving){
    if(isMoving){
        owner->getTransform()->set(v.x, v.y);
        owner->getRigidBody()->setForce(0, 0);
    }else{
        c->getOwner()->getTransform()->set(v.x, v.y);
        c->getOwner()->getRigidBody()->setForce(0, 0);
    }
}