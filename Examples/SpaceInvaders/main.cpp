//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(720, 480, AX_WINDOWED, "Pong Game")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }

    //create the scene
    Scene* scene = new Scene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(200, 200, 200);

    //player1's paddle
    Entity* enemy = new Entity("enemy", 0, 0, 25, 80);
    enemy->addCollider(new BoxCollider());
    scene->addEntity(enemy);

    return AXWindow::run();
}