#include "exampleComponent.hpp"


void exampleComponent::update(){
    // This is the custom update, here you can access the entity it's attached to using "owner"
    //reset the colour here so onHover is temporary!
    owner->setColour(0, 0, 0, 255);
    //Input is a static class that allows you to get the user input
    if(Input::keyUp()){
        //this line gets a pointer to the rigidBody attached to the owner
        //it then adds an upwards force to it, the rigidBody handles the rest 
		owner->getRigidBody()->addForce(0, -10);
        //set the colour of the entity
        owner->setColour(0, 255, 255, 255);
        if(Client::getInstance()->isConnected()){
            Client::getInstance()->sendPacket();
        }
	}
    if(Input::keyRight()){
        owner->setColour(255, 0, 255, 255);
		owner->getRigidBody()->addForce(2, 0);
	}
    if(Input::keyLeft()){
        owner->setColour(0, 255, 0, 255);
		owner->getRigidBody()->addForce(-2, 0);
	}
}

void exampleComponent::onHover(){
    //this is an overriden method that's called when an entity with a collider is hovered over with the mouse
    owner->setColour(255, 0, 0, 255);
}