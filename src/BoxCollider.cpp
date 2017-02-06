#include "headers/BoxCollider.hpp"
#include "headers/Entity.hpp"

BoxCollider::BoxCollider(){
}

int BoxCollider::worldCollideCheck(Math::Vector2D& v){
    //get the bounds
    Math::Vector2D position = bounds->getPosition();
    Math::Vector2D size = bounds->getSize();
    //  get the offset between the collider and the entity
    // float xOffset = position.x - owner->getTransform()->getPos().x;
    //  float yOffset = position.y - owner->getTransform()->getPos().y;
    int screenWidth = AXWindow::getWidth()-owner->getScene()->getRenderOffset().x;
    int screenHeight = AXWindow::getHeight()-owner->getScene()->getRenderOffset().y;
    int screenWidthOrigin = -owner->getScene()->getRenderOffset().x;
    int screenHeightOrigin = -owner->getScene()->getRenderOffset().y;
    //if it goes out of the screen downwards
    if(position.y+size.y+v.y >= screenHeight){
        v.y = 0;
        this->bounds->set(position.x, screenHeight - size.y, size.x, size.y);
        owner->getTransform()->set(position.x, screenHeight - size.y, size.x, size.y);
        return AX_COLLIDE_DOWN;
    }
    //if it goes out of the screen upwards
    if(position.y+v.y < screenHeightOrigin){
        v.y = 0;
        this->bounds->set(position.x, screenHeightOrigin, size.x, size.y);
        owner->getTransform()->set(position.x, screenHeightOrigin, size.x, size.y);
        return AX_COLLIDE_UP;
    }
    //if it goes out of the screen rightways
    if(position.x+size.x+v.x >= screenWidth){
        v.x = 0;
        this->bounds->set(screenWidth-size.x, position.y, size.x, size.y);
        owner->getTransform()->set(screenWidth-size.x, position.y, size.x, size.y);
        return AX_COLLIDE_RIGHT;
    }
    //if it goes out of the screen leftways
    if(position.x+v.x < screenWidthOrigin){
        v.x = 0;
        this->bounds->set(screenWidthOrigin, position.y, size.x, size.y);
        owner->getTransform()->set(screenWidthOrigin, position.y, size.x, size.y);
        return AX_COLLIDE_LEFT;
    }
    return 0;
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
//    bool collisionHappened = false;
        //else if you're going down
    if(proposedMovement.y > 0){
        Math::Vector2D bottomLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y);
        if(Math::isInsideQuad(bottomLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            proposedMovement.y = 0;
            // std::cout << "Bottom Left" << std::endl;
            return true;
        }
        //if e's bottom right will be inside of this
        Math::Vector2D bottomRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y);
        if(Math::isInsideQuad(bottomRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            // std::cout << "Bottom Right" << std::endl;
            return true;
        }
        //middle
        Math::Vector2D middle = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x/2, ((otherBounds->getPosition().y+otherBounds->getSize().y)/2)+proposedMovement.y);
        if(Math::isInsideQuad(middle, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            // std::cout << "Bottom Right" << std::endl;
            return true;
        }

        Math::Vector2D topRightThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topRightThis.x, topRightThis.y, otherBounds->getPosition().x,otherBounds->getPosition().y+proposedMovement.y, otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y)){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            // std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D topLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topLeftThis.x, topLeftThis.y, otherBounds->getPosition().x,otherBounds->getPosition().y+proposedMovement.y, otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y)){
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            proposedMovement.y= 0;
            // std::cout << "Top Left This" << std::endl;
            return true;
        }
        Math::Vector2D middleThis = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x/2, bounds->getPosition().y+bounds->getSize().y/2);
        if(Math::isInsideQuad(middleThis.x, middleThis.y, otherBounds->getPosition().x,otherBounds->getPosition().y+proposedMovement.y, otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y)){
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y-otherBounds->getSize().y);
            proposedMovement.y= 0;
            // std::cout << "Middle This" << std::endl;
            return true;
        }

    // else if e is moving upwards
    }else if(proposedMovement.y < 0){
        Math::Vector2D topRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+proposedMovement.y);
        if(Math::isInsideQuad(topRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
            // std::cout << "Top Right" << std::endl;
            return true;
        }
        Math::Vector2D topLeft = Math::Vector2D(otherBounds->getPosition().x, otherBounds->getPosition().y+proposedMovement.y);
        if(Math::isInsideQuad(topLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
            // std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D middle = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x/2, (otherBounds->getPosition().y+otherBounds->getSize().y/2)+proposedMovement.y);
        if(Math::isInsideQuad(middle, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
            // std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D bottomRightThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
        if(Math::isInsideQuad(bottomRightThis.x, bottomRightThis.y, otherBounds->getPosition().x,otherBounds->getPosition().y+proposedMovement.y, otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y)){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
            // std::cout << "going up Bottom right this" << std::endl;
            return true;
        }
        Math::Vector2D bottomLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
        if(Math::isInsideQuad(bottomLeftThis.x, bottomLeftThis.y, otherBounds->getPosition().x,otherBounds->getPosition().y+proposedMovement.y, otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y)){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
            // std::cout << "Bottom Left This" << std::endl;
            return true;
        }
        Math::Vector2D middleThis = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x/2, bounds->getPosition().y+bounds->getSize().y/2);
        if(Math::isInsideQuad(middleThis.x, middleThis.y, otherBounds->getPosition().x,otherBounds->getPosition().y+proposedMovement.y, otherBounds->getPosition().x+otherBounds->getSize().x, otherBounds->getPosition().y+otherBounds->getSize().y+proposedMovement.y)){
            proposedMovement.y = 0;
            e->getTransform()->set(otherBounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
            // std::cout << "Middle This" << std::endl;
            return true;
        }


    }
    if(proposedMovement.x > 0){
        //if e's top right will be inside of this
        Math::Vector2D topRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y);
        if(Math::isInsideQuad(topRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-e->getTransform()->getSize().x, e->getTransform()->getPos().y);
            // std::cout << "Top Right" << std::endl;
            return true;
        }
        //if e's bottom right will be inside of this
        Math::Vector2D bottomRight = Math::Vector2D(otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y);
        if(Math::isInsideQuad(bottomRight, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-otherBounds->getSize().x, otherBounds->getPosition().y);
            // std::cout << "Bottom Right" << std::endl;
            return true;
        }
        Math::Vector2D middle = Math::Vector2D((otherBounds->getPosition().x+otherBounds->getSize().x/2)+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y/2);
        if(Math::isInsideQuad(middle, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-otherBounds->getSize().x, otherBounds->getPosition().y);
            // std::cout << "Bottom Right" << std::endl;
            return true;
        }
        //if this's top left will be inside of e
        Math::Vector2D topLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topLeftThis.x, topLeftThis.y, otherBounds->getPosition().x+proposedMovement.x,otherBounds->getPosition().y, otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y)){
            e->getTransform()->set(bounds->getPosition().x-otherBounds->getSize().x, otherBounds->getPosition().y);
            proposedMovement.x = 0;
            // std::cout << "Top Left This" << std::endl;
            return true;
        }
        //if this's bottom left will be inside of e
        Math::Vector2D bottomLeftThis = Math::Vector2D(bounds->getPosition().x, bounds->getPosition().y+bounds->getSize().y);
        if(Math::isInsideQuad(bottomLeftThis.x, bottomLeftThis.y, otherBounds->getPosition().x+proposedMovement.x,otherBounds->getPosition().y, otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y)){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-otherBounds->getSize().x, otherBounds->getPosition().y);
            // std::cout << "Bottom Left This" << std::endl;
            return true;
        }
        Math::Vector2D middleThis = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x/2, bounds->getPosition().y+bounds->getSize().y/2);
        if(Math::isInsideQuad(middleThis.x, middleThis.y, otherBounds->getPosition().x+proposedMovement.x,otherBounds->getPosition().y, otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y)){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x-otherBounds->getSize().x, otherBounds->getPosition().y);
            // std::cout << "Bottom Left This" << std::endl;
            return true;
        }



    }else if(proposedMovement.x < 0){
        Math::Vector2D topLeft = Math::Vector2D(otherBounds->getPosition().x+proposedMovement.x, otherBounds->getPosition().y);
        if(Math::isInsideQuad(topLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, otherBounds->getPosition().y);
            proposedMovement.x = 0;
            // std::cout << "Top Left" << std::endl;
            return true;
        }
        Math::Vector2D bottomLeft = Math::Vector2D(otherBounds->getPosition().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y);
        if(Math::isInsideQuad(bottomLeft, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, otherBounds->getPosition().y);
            proposedMovement.x = 0;
            // std::cout << "Bottom Left" << std::endl;
            return true;
        }
        Math::Vector2D middle = Math::Vector2D((otherBounds->getPosition().x+otherBounds->getSize().x/2)+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y/2);
        if(Math::isInsideQuad(middle, bounds->getPosition(), bounds->getPosition()+bounds->getSize())){
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, otherBounds->getPosition().y);
            proposedMovement.x = 0;
            // std::cout << "Bottom Left" << std::endl;
            return true;
        }
        Math::Vector2D topRightThis = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y);
        if(Math::isInsideQuad(topRightThis.x, topRightThis.y, otherBounds->getPosition().x+proposedMovement.x,otherBounds->getPosition().y, otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y)){
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, otherBounds->getPosition().y);
            proposedMovement.x = 0;
            // std::cout << "Top Right this" << std::endl;
            return true;
        }
        Math::Vector2D bottomRightThis = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x, bounds->getPosition().y+bounds->getSize().y);
        if(Math::isInsideQuad(bottomRightThis.x, bottomRightThis.y, otherBounds->getPosition().x+proposedMovement.x,otherBounds->getPosition().y, otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y)){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, e->getTransform()->getPos().y);
            // std::cout << "bottom right this" << std::endl;
            return true;
        }
        Math::Vector2D middleThis = Math::Vector2D(bounds->getPosition().x+bounds->getSize().x/2, bounds->getPosition().y+bounds->getSize().y/2);
        if(Math::isInsideQuad(middleThis.x, middleThis.y, otherBounds->getPosition().x+proposedMovement.x,otherBounds->getPosition().y, otherBounds->getPosition().x+otherBounds->getSize().x+proposedMovement.x, otherBounds->getPosition().y+otherBounds->getSize().y)){
            proposedMovement.x = 0;
            e->getTransform()->set(bounds->getPosition().x+bounds->getSize().x, e->getTransform()->getPos().y);
            // std::cout << "bottom right this" << std::endl;
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
    if(Math::isInsideQuad(Input::mouseX, Input::mouseY, bounds->getPosition().x+owner->getScene()->getRenderOffset().x, bounds->getPosition().y+owner->getScene()->getRenderOffset().y, bounds->getPosition().x+bounds->getSize().x+owner->getScene()->getRenderOffset().x, bounds->getPosition().y+bounds->getSize().y+owner->getScene()->getRenderOffset().y)){
        owner->onHover();
        if(Input::mouseIsPressed){
            owner->onClick(Input::mouseButton);
        }
    }
}

Collider* BoxCollider::clone(){
    BoxCollider* bc = new BoxCollider();
    bc->bounds = bounds->clone();
    bc->center = this->center;
    bc->halfSize = this->halfSize;
    return bc;
}
