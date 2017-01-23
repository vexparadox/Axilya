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
    // getScene()->offsetRenderer(owner->getTransform()->getPos());
    //Input is a static class that allows you to get the user input
    if(Input::keyUp()|| Input::getKey("W") || Input::getKey("GC1_A")){
        //this line gets a pointer to the rigidBody attached to the owner
        //it then adds an upwards force to it, the rigidBody handles the rest core
		owner->getRigidBody()->addForce(0, -5);
	}
    if(Input::keyRight()|| Input::getKey("D") || Input::getKey("GC2_DRIGHT")){
		owner->getRigidBody()->addForce(1.5, 0);
	}
    if(Input::keyLeft() || Input::getKey("A") || Input::getKey("GC1_DLEFT")){
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
