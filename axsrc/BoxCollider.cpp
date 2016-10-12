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
    //e is the moving entity
    //get the moving entities bounds
    Shape* otherBounds = e->getCollider()->getBounds();
    //if moving right
    if(proposedMovement.x > 0){
        //if e's top right will be inside of this
        Math::Vector2D topRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y);
        if(Math::isInsideQuad(topRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            return true;
        }
        //if this will be inside of e
        Math::Vector2D topLeftThis = Math::Vector2D(bounds->getPosition().x-proposedMovement.x, bounds->getPosition().y);
        if(Math::isInsideQuad(topLeftThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.x = 0;
            return true;
        }
    }else if(proposedMovement.x < 0){
        Math::Vector2D topLeft = Math::Vector2D(otherBounds->getPosition().x-proposedMovement.x, otherBounds->getPosition().y);
        if(Math::isInsideQuad(topLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            return true;
        }
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
