//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>
#include "PlayerController.hpp"
#include "Invader.hpp"
#include "Bullet.hpp"


void SpawnPlayer(AXScene* scene){
    AXEntity* player = new AXEntity("player", 0, AXWindow::getHeight()-64, 64, 64);
    player->addComponent(new PlayerController());
    //create a sprite
    AXStaticSprite* ss = new AXStaticSprite("player_static", "player_1.jpg");
    player->getRenderer()->addSprite(ss);
    scene->addEntity(player);

    AXEntity* bullet = new AXEntity("bullet", 0, 0, 32, 64);
    bullet->addCollider(new AXBoxCollider());
    bullet->addComponent(new Bullet());
    ss = new AXStaticSprite("bullet", "bullet.jpg");
    bullet->getRenderer()->addSprite(ss);
    PrefabManager::getInstance()->addPrefab(bullet);
}

void SpawnInvaders(AXScene* scene){
    PrefabManager* prefabManager = PrefabManager::getInstance();
    //A prefab of the invaders
    AXEntity* enemy = new AXEntity("enemy", 0, 0, 64, 64);
    enemy->addCollider(new AXBoxCollider());
    enemy->addComponent(new Invader());
    //create a new animated sprite
    AXAnimatedSprite* as = new AXAnimatedSprite("enemy_move", 30);
    as->addTexture("enemy_1.jpg");
    as->addTexture("enemy_2.jpg");
    //add the sprite to the enemy
    //this will also set it to the current one
    enemy->getRenderer()->addSprite(as);

    //make the enemy a prefab so we can make copies easily
    prefabManager->addPrefab(enemy);

    int cols = (AXWindow::getWidth()/64);
    int rows = 5;
    //make a grid of enemies
    for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
            //spawn an entity with the name "enemy_col_row"
            //use the row and col numbers to determine it's position
            scene->instantiate(
                "enemy_"+std::to_string(i)+"_"+std::to_string(j), 
                prefabManager->getPrefab("enemy"),
                new AXTransform((i*64)+10, j*64, 64, 64));
        }
    }
}

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(720, 480, AX_WINDOWED, "Space Invaders")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    //create the scene
    AXScene* scene = new AXScene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(16, 16, 16, 255);

    //spawn the invaders
    SpawnInvaders(scene);
    //spawn the player
    SpawnPlayer(scene);

    return AXWindow::run();
}