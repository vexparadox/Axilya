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

void MakeBlocks(AXScene* scene){
    AXEntity* block = new AXEntity(std::string("block1"), 0, 0, 40, 20);
    SDL_assert(block);
    block->setColour(230, 230, 230);
    block->addCollider(new AXBoxCollider());
    AXPrefabManager::getInstance()->addPrefab(block);
    for(int j = 0; j < 6; j++){
        for(int i = 0; i < 15; i++){
            scene->instantiate("block_"+std::to_string(i)+"_"+std::to_string(j), 
            AXPrefabManager::getInstance()->getPrefab("block1"),
            new AXTransform((i*80)+60, (j*40)+30, 40, 10),
            0);
        }
    }
}

void SpawnPlayer(AXScene* scene){
    AXEntity* player = new AXEntity("player", AXWindow::getWidth()/2, AXWindow::getHeight()-25, 80, 20);
    player->setColour(200, 200, 200);
    player->addCollider(new AXBoxCollider());
    player->addComponent(new PlayerController());
    scene->addEntity(player);
}

void SpawnBall(AXScene* scene){
    AXEntity* ball = new AXEntity("ball", 50, AXWindow::getHeight()/2, 20, 20);
    ball->setColour(255, 255, 255);
    ball->addCollider(new AXBoxCollider());
    ball->addComponent(new BallController());
    scene->addEntity(ball);
}

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(1280, 720, "Breakout", AX_DEFAULT)){
        AXLog::log("Window failed to initialise", "Quitting", AX_LOG_ERROR);
    	return -1;
    }
    AXWindow::hideCursor(true);
    AXWindow::lockCursor(true);

    //create the scene
    AXScene* scene = new AXScene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(20, 20, 20);

    SpawnPlayer(scene);
    SpawnBall(scene);
    MakeBlocks(scene);

    //the game master (keeps track of score)
    AXEntity* gameMaster = new AXEntity("GM");
    gameMaster->addComponent(new GameMaster());
    scene->setGameMaster(gameMaster);

    return AXWindow::run();
}