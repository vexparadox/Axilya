#include "exampleComponent.hpp"

exampleComponent::exampleComponent(){
}

void exampleComponent::update(){
    // This is the custom update, here you can access the entity it's attached to using "owner"
    //Input is a static class that allows you to get the user input
    if(Input::keyUp()){
        //this line gets a pointer to the rigidBody attached to the owner
        //it then adds an upwards force to it, the rigidBody handles the rest 
		owner->getRigidBody()->addForce(0, -4);
	}
    if(Input::keyRight()){
		owner->getRigidBody()->addForce(2, 0);
	}
    if(Input::keyLeft()){
		owner->getRigidBody()->addForce(-2, 0);
	}
}