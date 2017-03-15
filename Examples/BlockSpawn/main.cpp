//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>
#include "PlayerMove.hpp"
bool down = false;

AXScene* s;
int blockCount = 0;

void update(){
    if(AXInput::mouseIsPressed && !down){
        down = true;
        s->instantiate("box" + std::to_string(blockCount++),
            AXPrefabManager::getInstance()->getPrefab("block"),
            new AXTransform(AXInput::mouseX - 10, 
                          AXInput::mouseY - 10,
                          20,
                          20)
            );
    }

    if(!AXInput::mouseIsPressed && down){
        down = false;
    }
}

int main(int argc, char *argv[])
{
    //initialise the window
    if(!AXWindow::init(720, 480, "BlockSpawn Example", AX_DEFAULT, update, 0)){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    //create a AXScene
    s = new AXScene();
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

    e = new AXEntity("block", 0, 0, 20, 20);
    e->addCollider(new AXBoxCollider());
    AXPrefabManager::getInstance()->addPrefab(e);
    //return the window run
    return AXWindow::run();
}