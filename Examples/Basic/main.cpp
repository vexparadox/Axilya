//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include <Axilya/AXMain.h>

int main(int argc, char *argv[])
{
    if(!AXWindow::init(720, 480, AX_WINDOWED, "Basic Example")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    Scene* s = new Scene();
    AXWindow::setCurrentScene(s);
    Entity* e = new Entity("blob", 10, 10, 10, 10);
    e->addCollider(new BoxCollider);
    e->addRigidBody(true);
    s->addEntity(e);
    return AXWindow::run();
}