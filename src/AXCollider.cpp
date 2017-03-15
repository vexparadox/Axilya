#include "headers/AXCollider.hpp"
#include "headers/AXEntity.hpp"
AXCollider::AXCollider(){
    screenBound = true;
}

AXCollider::~AXCollider(){
	delete bounds;
}

AXShape* AXCollider::getBounds(){
    return bounds;
}

void AXCollider::setOwner(AXEntity* e){
	this->owner = e;
}



AXEntity* AXCollider::getOwner(){
	return owner;
}
