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
    //initialise the window
    if(!AXWindow::init(720, 480, AX_WINDOWED, "BasicComponent Example")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    //create a AXScene
    AXScene* s = new AXScene();
    //set the Window to draw and update the current AXScene
    AXWindow::setCurrentScene(s);
    //make a new AXEntity
    AXEntity* e = new AXEntity("player", 10, 10, 30, 30);
    //attach a box collider
    e->addCollider(new AXBoxCollider);
    //attach a rigidbody with gravity
    e->addRigidBody(true);
    //attach our custom component written in PlayerMove.hpp
    e->addComponent(new PlayerMove());
    //add the entity to the scene
    s->addEntity(e);

    e = new AXEntity("block", 600, 400, 100, 80);
    e->addCollider(new AXBoxCollider());
    s->addEntity(e);
    //return the window run
    return AXWindow::run();
}