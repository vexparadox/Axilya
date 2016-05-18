
#include "Collider.hpp"
#include "Entity.hpp"

Collider::Collider(Entity* owner, Shape* bounds) : Component(owner), bounds(bounds){
    
}

Shape* Collider::getBounds(){
    return bounds;
}

bool Collider::collideCheck(){
    return false;
}