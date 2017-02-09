//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>
#include "GameMaster.hpp"
#include "PlayerController.hpp"
#include "BallController.hpp"

void MakeBlocks(Scene* scene){
    Entity* block = new Entity(std::string("block1"), 0, 0, 40, 20);
    SDL_assert(block);
    block->setColour(230, 230, 230);
    block->addCollider(new BoxCollider());
    PrefabManager::getInstance()->addPrefab(block);
    for(int j = 0; j < 6; j++){
        for(int i = 0; i < 15; i++){
            scene->instantiate("block_"+std::to_string(i)+"_"+std::to_string(j), 
            PrefabManager::getInstance()->getPrefab("block1"),
            new Transform((i*80)+60, (j*40)+30, 40, 10));
        }
    }
}

void SpawnPlayer(Scene* scene){
    Entity* player = new Entity("player", AXWindow::getWidth()/2, AXWindow::getHeight()-25, 80, 20);
    player->setColour(200, 200, 200);
    player->addCollider(new BoxCollider());
    player->addComponent(new PlayerController());
    scene->addEntity(player);
}

void SpawnBall(Scene* scene){
    Entity* ball = new Entity("ball", 50, AXWindow::getHeight()/2, 20, 20);
    ball->setColour(255, 255, 255);
    ball->addCollider(new BoxCollider());
    ball->addComponent(new BallController());
    scene->addEntity(ball);
}

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(1280, 720, AX_WINDOWED, "Breakout")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    AXWindow::hideCursor(true);
    AXWindow::lockCursor(true);

    //create the scene
    Scene* scene = new Scene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(20, 20, 20);

    SpawnPlayer(scene);
    SpawnBall(scene);
    MakeBlocks(scene);

    //the game master (keeps track of score)
    Entity* gameMaster = new Entity("GM");
    gameMaster->addComponent(new GameMaster());
    scene->setGameMaster(gameMaster);

    return AXWindow::run();
}