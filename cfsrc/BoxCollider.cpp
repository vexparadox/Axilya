#include "BoxCollider.hpp"
#include "Entity.hpp"

BoxCollider::BoxCollider(Entity* owner) : Collider(owner){
    
}

bool BoxCollider::collideCheck(){
    return false;
}