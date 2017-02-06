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
#include "GameMaster.hpp"

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
    Entity* player1 = new Entity("Player1", 0, 0, 25, 80);
    player1->addCollider(new BoxCollider());
    player1->addComponent(new PlayerOneController());
    scene->addEntity(player1);

    //player2's paddle
    Entity* player2 = new Entity("Player2", AXWindow::getWidth()-25, 0, 25, 80);
    player2->addCollider(new BoxCollider());
    player2->addComponent(new PlayerTwoController());
    scene->addEntity(player2);

    //the ball
    Entity* ball = new Entity("ball", AXWindow::getWidth()/2, AXWindow::getHeight()/2, 20, 20);
    ball->setColour(200, 70, 0);
    ball->addCollider(new BoxCollider());
    ball->addComponent(new BallController());
    ball->setDrawType(AX_DRAW_ELLIPSE);
    scene->addEntity(ball);

    //the game master (keeps track of score)
    Entity* gameMaster = new Entity("GM");
    gameMaster->addComponent(new GameMaster());
    scene->setGameMaster(gameMaster);

    return AXWindow::run();
}