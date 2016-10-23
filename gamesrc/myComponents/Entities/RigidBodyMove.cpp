#include "RigidBodyMove.hpp"


void RigidBodyMove::start(){
    //this is called after the Core Setup
    //you'll manually have to call this method if you're creating components after the Core Setup

    //lets save a pointer to the GameMaster Component on the GameMaster Entity
    this->gm = getScene()->getGameMaster()->getComponent<GameMaster>();
}

void RigidBodyMove::update(){
    // This is the custom update, here you can access the entity it's attached to using "owner"
    //reset the colour here so onHover is temporary!
    owner->setColour(0, 0, 0, 255);
    //Input is a static class that allows you to get the user input
    if(Input::keyUp()|| Input::getKey("W")){
        //this line gets a pointer to the rigidBody attached to the owner
        //it then adds an upwards force to it, the rigidBody handles the rest core
		owner->getRigidBody()->addForce(0, -5);
        //set the colour of the entity
        if(Client::getInstance()->isConnected()){
            Client::getInstance()->sendPacket();
        }
	}
    if(Input::keyRight()|| Input::getKey("D")){
		owner->getRigidBody()->addForce(1.5, 0);
	}
    if(Input::keyLeft() || Input::getKey("A")){
		owner->getRigidBody()->addForce(-1.5, 0);
	}
}

void RigidBodyMove::onHover(){
    //this is an overriden method that's called when an entity with a collider is hovered over with the mouse
    owner->setColour(255, 0, 0, 255);
}

void RigidBodyMove::onCollision(Entity* e){
    //access the GameMaster component we saved in start
    gm->increaseScore();
    if(gm->getScore() > 4000){
        std::cout << "You win!" << std::endl;
        gm->gameOver();
    }
}