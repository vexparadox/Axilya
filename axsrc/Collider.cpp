
#include "Collider.hpp"
#include "Entity.hpp"

Collider::Collider(){
    
}

Shape* Collider::getBounds(){
    return bounds;
}