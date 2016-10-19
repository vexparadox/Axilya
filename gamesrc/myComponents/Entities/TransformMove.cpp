//
// Created by William Meaton on 13/09/2016.
//

#include "TransformMove.hpp"

void TransformMove::update() {
	//this is how you move the transform only.
	//this will not move Collider bounds
	owner->getTransform()->getPos()->moveTransform(1, 1);
}