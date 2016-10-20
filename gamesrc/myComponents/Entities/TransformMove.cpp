//
// Created by William Meaton on 13/09/2016.
//

#include "TransformMove.hpp"

void TransformMove::update() {
	//this is how you move the transform only.
	//this will not move Collider bounds
	if(Input::getKey("RIGHT")){
		owner->getTransform()->moveTransform(Math::Vector2D(1, 0));
		if(owner->getCollider()){
			owner->getCollider()->getBounds()->moveShape(Math::Vector2D(1, 0));
		}
	}
}