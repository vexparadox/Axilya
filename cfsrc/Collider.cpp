
#include "Collider.hpp"
#include "Entity.hpp"

Collider::Collider(Entity* owner) : Component(owner){
    
}

Shape* Collider::getBounds(){
    return bounds;
}