//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//

#include <Axilya/AXMain.h>
#include "PlayerMove.hpp"
int main(int argc, char *argv[])
{
    if(!AXWindow::init(720, 480, "Basic Example", AX_DEFAULT)){
    	AXLog::log("Window failed to initialise", "Quitting", AX_LOG_ERROR);
    	return -1;
    }
    //build a scene
    AXScene* s = new AXScene();
    //Give the window the scene to manage
    AXWindow::setCurrentScene(s);

    //lets load the audio
    int playerAudio = AXResourceManager::getInstance()->addAudioChunk("example.wav");
    //create an entity
    AXEntity* e = new AXEntity("blob", 10, 10, 200, 200);
    //add a new component where we will play the sound when it hits the floor
    e->addComponent(new PlayerMove()); 
    e->addCollider(new AXBoxCollider()); //add a collider
    e->addRigidBody(true); // make the box fall
    //add the audio we just loaded onto the entity, give it the name "playerAudio"
    e->getAudioPlayer()->addAudioChunk(playerAudio, "playerAudio");

    //add the entity to the scene
    s->addEntity(e);
    //return the window run, this is where the game will loop
    return AXWindow::run();

}