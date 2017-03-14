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
    AXScene* scene = new AXScene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(200, 200, 200);

    //player1's paddle
    AXEntity* player1 = new AXEntity("Player1", 0, 0, 25, 80);
    player1->addCollider(new AXBoxCollider());
    player1->addComponent(new PlayerOneController());
    scene->addEntity(player1);

    //player2's paddle
    AXEntity* player2 = new AXEntity("Player2", AXWindow::getWidth()-25, 0, 25, 80);
    player2->addCollider(new AXBoxCollider());
    player2->addComponent(new PlayerTwoController());
    scene->addEntity(player2);

    //the ball
    AXEntity* ball = new AXEntity("ball", AXWindow::getWidth()/2, AXWindow::getHeight()/2, 20, 20);
    ball->setColour(200, 70, 0);
    ball->addCollider(new AXBoxCollider());
    ball->addComponent(new BallController());
    ball->setDrawType(AX_DRAW_ELLIPSE);
    scene->addEntity(ball);

    //the game master (keeps track of score)
    AXEntity* gameMaster = new AXEntity("GM");
    gameMaster->addComponent(new GameMaster());
    scene->setGameMaster(gameMaster);

    return AXWindow::run();
}