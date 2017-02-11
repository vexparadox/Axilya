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

int BoxCollider::checkMovement(Entity* e, Math::Vector2D& proposedMovement){
    //the entities 
    Shape* box1 = e->getCollider()->getBounds();
    //these bounds
    Shape* box2 = this->bounds;
    float w = 0.5 * (box1->getSize().x + box2->getSize().x);
    float h = 0.5 * (box1->getSize().y + box2->getSize().y);
    float deltax = (box1->getPosition().x+(box1->getSize().x/2)) - (box2->getPosition().x+(box2->getSize().x/2));
    float deltay = (box1->getPosition().y+(box1->getSize().y/2)) - (box2->getPosition().y+(box2->getSize().y/2));
    // std::cout << "proposedMovement" << proposedMovement.x << "  " << proposedMovement.y << std::endl;
    if (Math::absolute(deltax) < w && Math::absolute(deltay) < h)
    {
        // std::cout << "Collide!" << std::endl;
        //collision!
        float wy = w * deltay;
        float hx = h * deltax;
        // std::cout << "dx: " << deltax << " dy: " << deltay << " h: " << h << std::endl;
        // std::cout << "wy: " << wy << " hx: " << hx << std::endl;
        if(wy > hx){
            if(wy > -hx){
                //bottom
                e->getTransform()->set(box1->getPosition().x, box2->getPosition().y+box2->getSize().y);
                box1->set(box1->getPosition().x, box2->getPosition().y+box2->getSize().y, box1->getSize().x, box1->getSize().y);
                proposedMovement.y = 0;
                return AX_COLLIDE_DOWN;

            }else{
                //left
                e->getTransform()->set(box2->getPosition().x-box1->getSize().x, box1->getPosition().y);
                box1->set(box2->getPosition().x-box1->getSize().x, box1->getPosition().y, box1->getSize().x, box1->getSize().y);
                proposedMovement.x = 0;
                return AX_COLLIDE_LEFT;            

            }
        }else{
            if(wy > -hx){
                //right
                e->getTransform()->set(box2->getPosition().x+box2->getSize().x, box1->getPosition().y);
                box1->set(box2->getPosition().x+box2->getSize().x, box1->getPosition().y, box1->getSize().x, box1->getSize().y);
                proposedMovement.x = 0;
                return AX_COLLIDE_RIGHT; 

            }else{
                //top
                e->getTransform()->set(box1->getPosition().x, box2->getPosition().y-box1->getSize().y);
                box1->set(box1->getPosition().x, box2->getPosition().y-box1->getSize().y, box1->getSize().x, box1->getSize().y);
                proposedMovement.y = 0;
                return AX_COLLIDE_UP;
            }
        }
        // if((box1->getPosition().y+box1->getSize().y)-proposedMovement.y <= box2->getPosition().y){
        //     // at the top
        //     std::cout << "Collision top" << std::endl;
        //     e->getTransform()->set(box1->getPosition().x, box2->getPosition().y-box1->getSize().y);
        //     box1->set(box1->getPosition().x, box2->getPosition().y-box1->getSize().y, box1->getSize().x, box1->getSize().y);
        //     proposedMovement.y = 0;
        //     return AX_COLLIDE_UP;
        // }
        // if((box1->getPosition().y+proposedMovement.y) >= box2->getPosition().y+box2->getSize().y){
        //     // collision at the bottom
        //     std::cout << "Collision bottom" << std::endl;
        //     e->getTransform()->set(box1->getPosition().x, box2->getPosition().y+box2->getSize().y);
        //     box1->set(box1->getPosition().x, box2->getPosition().y+box2->getSize().y, box1->getSize().x, box1->getSize().y);
        //     proposedMovement.y = 0;
        //     return AX_COLLIDE_DOWN;
        // }
        // if((box1->getPosition().x+box1->getSize().x)-proposedMovement.x <= box2->getPosition().x){
        //     // on the left 
        //     std::cout << "Collision left" << std::endl;
        //     e->getTransform()->set(box2->getPosition().x-box1->getSize().x, box1->getPosition().y);
        //     box1->set(box2->getPosition().x-box1->getSize().x, box1->getPosition().y, box1->getSize().x, box1->getSize().y);
        //     proposedMovement.x = 0;
        //     return AX_COLLIDE_LEFT;            
        // }
        // if(box1->getPosition().x+proposedMovement.x >= box2->getPosition().x+box2->getSize().x){
        //     // on the right 
        //     std::cout << "Collision right" << std::endl;
        //     e->getTransform()->set(box2->getPosition().x+box2->getSize().x, box1->getPosition().y);
        //     box1->set(box2->getPosition().x+box2->getSize().x, box1->getPosition().y, box1->getSize().x, box1->getSize().y);
        //     proposedMovement.x = 0;
        //     return AX_COLLIDE_RIGHT; 
        // }
    }
    return 0;
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
