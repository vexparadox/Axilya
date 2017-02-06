//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>
#include "PlayerOneController.hpp"
#include "PlayerTwoController.hpp"
#include "BallController.hpp"


int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(720, 480, AX_WINDOWED, "Pong Game")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }

    Scene* scene = new Scene();
    AXWindow::setCurrentScene(scene);

    Entity* player1 = new Entity("Player1", 0, 0, 25, 80);
    player1->addCollider(new BoxCollider());
    player1->addComponent(new PlayerOneController());
    scene->addEntity(player1);

    Entity* player2 = new Entity("Player2", AXWindow::getWidth()-25, 0, 25, 80);
    player2->addCollider(new BoxCollider());
    player2->addComponent(new PlayerTwoController());
    scene->addEntity(player2);

    Entity* ball = new Entity("ball", AXWindow::getWidth()/2, AXWindow::getHeight()/2, 20, 20);
    ball->setColour(255, 0, 0);
    ball->addComponent(new BallController());
    scene->addEntity(ball);
    //return the window run, this is where the update and draw will be called
    return AXWindow::run();
}