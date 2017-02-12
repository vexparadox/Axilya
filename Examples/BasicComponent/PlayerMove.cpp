#include "PlayerMove.hpp"

void PlayerMove::start(){
	//get the RigidBody attached to the owner object
	rb = owner->getRigidBody();
}
void PlayerMove::update(){
	if(rb){
		//if the D key is pressed, move to the right
		if(Input::getValue("D")){
			rb->addForce(1, 0);
		}
		//if the A key is pressed, move to the left
		if(Input::getValue("A")){
			rb->addForce(-1, 0);
		}
		//if the S key is pressed, move upwards
		if(Input::getValue("W")){
			rb->addForce(0, -5);
		}	
	}

	//if the player is touching the ground, make them red
	if(owner->isGrounded()){
		owner->setColour(255, 0, 0);
	}else{
		owner->setColour(0, 0, 0);
	}
}