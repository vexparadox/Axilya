#include "PlayerMove.hpp"

void PlayerMove::start(){
	//get the AXRigidBody attached to the owner object
	rb = owner->getRigidBody();
}
void PlayerMove::update(){
	if(rb){
		//if the D key is pressed, move to the right
		if(AXInput::getValue("D")){
			rb->addForce(1, 0);
		}
		//if the A key is pressed, move to the left
		if(AXInput::getValue("A")){
			rb->addForce(-1, 0);
		}
	}

	//if the player is touching the ground, make them red
	if(owner->isGrounded()){
		owner->setColour(255, 0, 0);
	}else{
		owner->setColour(0, 0, 0);
	}
}

void PlayerMove::onInput(const std::string& identifier, int value){
	// onInput tells you when keys have been pressed
	if(identifier == "W" && value == 1 && owner->isGrounded()){
		if(rb){
			rb->addForce(0, -30);
		}
	}

}