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
    bool collisionHappened = false;
        //else if you're going down
    if(proposedMovement.y > 0){
        Math::Vector2D bottomLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y);
        if(Math::isInsideQuad(bottomLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            proposedMovement.y = 0;
            std::cout << "Bottom Left" << std::endl;
            return true;
        }
        //if e's bottom right will be inside of this
        Math::Vector2D bottomRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y);
        if(Math::isInsideQuad(bottomRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            std::cout << "Bottom Right" << std::endl;
            return true;
        }
        Math::Vector2D topRightThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topRightThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D topLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topLeftThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.y= 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            std::cout << "Top Left This" << std::endl;
            return true;
        }
    }
    if(proposedMovement.x > 0){
        //if e's top right will be inside of this
        Math::Vector2D topRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y);
        if(Math::isInsideQuad(topRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-e->getTransform()->getSize().x, e->getTransform()->getPos().y);
            std::cout << "Top Right" << std::endl;
            return true;
        }
        //if e's bottom right will be inside of this
        Math::Vector2D bottomRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y);
        if(Math::isInsideQuad(bottomRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-e->getTransform()->getSize().x, e->getTransform()->getPos().y);
            std::cout << "Bottom Right" << std::endl;
            return true;
        }
        //if this's top left will be inside of e
        Math::Vector2D topLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topLeftThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-e->getTransform()->getSize().x, e->getTransform()->getPos().y);
            std::cout << "Top Left This" << std::endl;
            return true;
        }
        //if this's bottom left will be inside of e
        Math::Vector2D bottomLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
        if(Math::isInsideQuad(bottomLeftThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-e->getTransform()->getSize().x, e->getTransform()->getPos().y);
            std::cout << "Bottom Left This" << std::endl;
            return true;
        }

    }else if(proposedMovement.x < 0){
        Math::Vector2D topLeft = Math::Vector2D(otherBounds->getPosition().x-proposedMovement.x, otherBounds->getPosition().y);
        if(Math::isInsideQuad(topLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, e->getTransform()->getPos().y);
            proposedMovement.x = 0;
            std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D bottomLeft = Math::Vector2D(otherBounds->getPosition().x-proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y);
        if(Math::isInsideQuad(bottomLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, e->getTransform()->getPos().y);
            proposedMovement.x = 0;
            std::cout << "Bottom Left" << std::endl;
            return true;
        }
        Math::Vector2D topRightThis = Math::Vector2D(bounds->getPosition().x-proposedMovement.x, bounds->getPosition().y);
        if(Math::isInsideQuad(topRightThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, e->getTransform()->getPos().y);
            std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D bottomRightThis = Math::Vector2D(bounds->getPosition().x-proposedMovement.x, bounds->getPosition().y+bounds->getSize().y);
        if(Math::isInsideQuad(bottomRightThis, otherBounds->getPosition(), otherBounds->getPosition()+otherBounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, e->getTransform()->getPos().y);
            std::cout << "Top Left" << std::endl;
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
