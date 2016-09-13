#include "RigidBodyMove.hpp"


void RigidBodyMove::update(){
    // This is the custom update, here you can access the entity it's attached to using "owner"
    //reset the colour here so onHover is temporary!
    owner->setColour(0, 0, 0, 255);
    //Input is a static class that allows you to get the user input
    if(Input::keyUp()|| Input::getKey("W")){
        //this line gets a pointer to the rigidBody attached to the owner
        //it then adds an upwards force to it, the rigidBody handles the rest core
		owner->getRigidBody()->addForce(0, -10);
        //set the colour of the entity
        owner->setColour(0, 255, 255, 255);
        if(Client::getInstance()->isConnected()){
            Client::getInstance()->sendPacket();
        }
	}
    if(Input::keyRight()|| Input::getKey("D")){
        owner->setColour(255, 0, 255, 255);
		owner->getRigidBody()->addForce(2, 0);
	}
    if(Input::keyLeft() || Input::getKey("A")){
        owner->setColour(0, 255, 0, 255);
		owner->getRigidBody()->addForce(-2, 0);
	}
    //you can get other entities in the same scene using their name
    Entity* otherEntity = getScene()->findEntity("small_box");
}

void RigidBodyMove::onHover(){
    //this is an overriden method that's called when an entity with a collider is hovered over with the mouse
    owner->setColour(255, 0, 0, 255);
}