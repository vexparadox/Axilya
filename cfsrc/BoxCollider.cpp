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

void BoxCollider::correctColliderCollision(Collider *c, const Math::Vector2D& v, bool isMoving){
    if(isMoving){
        owner->getTransform()->set(v.x, v.y);
        owner->getRigidBody()->setForce(0, 0);
    }else{
        c->getOwner()->getTransform()->set(v.x, v.y);
        c->getOwner()->getRigidBody()->setForce(0, 0);
    }
}

void BoxCollider::mouseCheck(){
    if(Math::isInsideQuad(Input::mouseX, Input::mouseY, bounds->getPosition().x, bounds->getPosition().y, bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y+bounds->getSize().y)){
        owner->onHover();
        if(Input::mouseIsPressed){
            owner->onClick(Input::mouseButton);
        }
    }
}