#include "headers/AXBoxCollider.hpp"
#include "headers/AXEntity.hpp"

AXBoxCollider::AXBoxCollider(){
}

int AXBoxCollider::worldCollideCheck(AXVector2D& v){
    //get the bounds
    AXVector2D position = bounds->getPosition();
    AXVector2D size = bounds->getSize();
    //  get the offset between the collider and the entity
    int screenWidth = AXWindow::getWidth()-owner->getScene()->getRenderOffset().x;
    int screenHeight = AXWindow::getHeight()-owner->getScene()->getRenderOffset().y;
    int screenWidthOrigin = owner->getScene()->getRenderOffset().x;
    int screenHeightOrigin = owner->getScene()->getRenderOffset().y;
    // if it goes out of the screen downwards
    if(position.y+size.y > screenHeight){
        this->bounds->set(position.x, screenHeight - size.y, size.x, size.y);
        owner->getTransform()->set(position.x, screenHeight - size.y, size.x, size.y);
        return AX_COLLIDE_DOWN;
    }
    //if it goes out of the screen upwards
    if(position.y < screenHeightOrigin){
        this->bounds->set(position.x, screenHeightOrigin, size.x, size.y);
        owner->getTransform()->set(position.x, screenHeightOrigin, size.x, size.y);
        return AX_COLLIDE_UP;
    }
    //if it goes out of the screen rightways
    if(position.x+size.x > screenWidth){
        this->bounds->set(screenWidth-size.x, position.y, size.x, size.y);
        owner->getTransform()->set(screenWidth-size.x, position.y, size.x, size.y);
        return AX_COLLIDE_RIGHT;
    }
    //if it goes out of the screen leftways
    if(position.x < screenWidthOrigin){
        this->bounds->set(screenWidthOrigin, position.y, size.x, size.y);
        owner->getTransform()->set(screenWidthOrigin, position.y, size.x, size.y);
        return AX_COLLIDE_LEFT;
    }
    return 0;
}

int AXBoxCollider::checkMovement(AXEntity* e, AXVector2D& proposedMovement){
    //the entities
    AXShape* box1 = e->getCollider()->getBounds();
    //these bounds
    AXShape* box2 = this->bounds;
    float w = 0.5 * (box1->getSize().x + box2->getSize().x);
    float h = 0.5 * (box1->getSize().y + box2->getSize().y);
    float deltax = (box1->getPosition().x+(box1->getSize().x/2)) - (box2->getPosition().x+(box2->getSize().x/2));
    float deltay = (box1->getPosition().y+(box1->getSize().y/2)) - (box2->getPosition().y+(box2->getSize().y/2));
    if (Math::absolute(deltax) < w && Math::absolute(deltay) < h)
    {
        //collision!
        float wy = w * deltay;
        float hx = h * deltax;
        //by evaluating the 4 quads that the entitiy could have been in before the movement, we can work out where the collision occured.
        if((box1->getPosition().y+box1->getSize().y)-proposedMovement.y <= box2->getPosition().y){
            // at the top
            e->getTransform()->set(box1->getPosition().x, box2->getPosition().y-box1->getSize().y);
            box1->set(box1->getPosition().x, box2->getPosition().y-box1->getSize().y, box1->getSize().x, box1->getSize().y);
            return AX_COLLIDE_UP;
        }
        if((box1->getPosition().y+Math::absolute(proposedMovement.y)) >= box2->getPosition().y+box2->getSize().y){
            // collision at the bottom
            e->getTransform()->set(box1->getPosition().x, box2->getPosition().y+box2->getSize().y);
            box1->set(box1->getPosition().x, box2->getPosition().y+box2->getSize().y, box1->getSize().x, box1->getSize().y);
            return AX_COLLIDE_DOWN;
        }
        if((box1->getPosition().x+box1->getSize().x)-proposedMovement.x <= box2->getPosition().x){
            // on the left 
            e->getTransform()->set(box2->getPosition().x-box1->getSize().x, box1->getPosition().y);
            box1->set(box2->getPosition().x-box1->getSize().x, box1->getPosition().y, box1->getSize().x, box1->getSize().y);
            return AX_COLLIDE_LEFT;            
        }
        if(box1->getPosition().x+Math::absolute(proposedMovement.x) >= box2->getPosition().x+box2->getSize().x){
            // on the right 
            e->getTransform()->set(box2->getPosition().x+box2->getSize().x, box1->getPosition().y);
            box1->set(box2->getPosition().x+box2->getSize().x, box1->getPosition().y, box1->getSize().x, box1->getSize().y);
            return AX_COLLIDE_RIGHT; 
        }
    }
    return 0;
}

void AXBoxCollider::mouseCheck(){
    if(Math::isInsideQuad(AXInput::mouseX, AXInput::mouseY, bounds->getPosition().x+owner->getScene()->getRenderOffset().x, bounds->getPosition().y+owner->getScene()->getRenderOffset().y, bounds->getPosition().x+bounds->getSize().x+owner->getScene()->getRenderOffset().x, bounds->getPosition().y+bounds->getSize().y+owner->getScene()->getRenderOffset().y)){
        owner->onHover();
        if(AXInput::mouseIsPressed){
            owner->onClick(AXInput::mouseButton);
        }
    }
}

AXCollider* AXBoxCollider::clone(){
    AXBoxCollider* bc = new AXBoxCollider();
    bc->bounds = bounds->clone();
    bc->center = this->center;
    bc->halfSize = this->halfSize;
    return bc;
}
