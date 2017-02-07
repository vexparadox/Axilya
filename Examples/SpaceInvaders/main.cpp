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
    if(!AXWindow::init(720, 480, AX_WINDOWED, "Space Invaders")){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    PrefabManager* prefabManager = PrefabManager::getInstance();
    //create the scene
    Scene* scene = new Scene();
    AXWindow::setCurrentScene(scene);
    AXGraphics::setBackground(20, 20, 20, 255);

    //player1's paddle
    Entity* enemy = new Entity("enemy", 0, 0, 64, 64);
    enemy->addCollider(new BoxCollider());
    AnimatedSprite* as = new AnimatedSprite("enemy_move", 20);
    as->addTexture("enemy_1.jpg");
    as->addTexture("enemy_2.jpg");
    enemy->getRenderer()->addSprite(as);
    enemy->getRenderer()->setSprite(as);
    scene->addEntity(enemy);

    // enemy = new Entity("enemy2", 200, 0, 64, 64);
    // Sprite* s = as->clone();
    // enemy->getRenderer()->addSprite(s);
    // enemy->getRenderer()->setSprite(s);
    // scene->addEntity(enemy);


    // //make the enemy a prefab
    prefabManager->addPrefab(enemy);
    int cols = (AXWindow::getWidth()/64);
    int rows = 5;
    for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
            scene->instantiate(
                "enemy_"+std::to_string(i)+"_"+std::to_string(j), 
                prefabManager->getPrefab("enemy"),
                new Transform((i*64)+10, j*64, 64, 64));
        }
    }

    return AXWindow::run();
}