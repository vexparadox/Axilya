#include "headers/AXCollider.hpp"
#include "headers/Entity.hpp"
AXCollider::AXCollider(){
    screenBound = true;
}

AXCollider::~AXCollider(){
	delete bounds;
}

Shape* AXCollider::getBounds(){
    return bounds;
}

void AXCollider::setOwner(Entity* e){
	this->owner = e;
}



Entity* AXCollider::getOwner(){
	return owner;
}
