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
    //initialise the AXWindow, this follows:
    //init(width, height, title, flags)
    //you can | (or) flags together - AX_DEFAULT | AX_NOAUDIO means we want default settings but no audio
    //it will return -1 on failure
    if(!AXWindow::init(720, 480, "Basic Example", AX_DEFAULT | AX_NOAUDIO)){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    //create a AXScene
    //Scenes are where all your entities live
    //the AXScene will update all your variables
    AXScene* s = new AXScene();
    
    //Give the window the scene to manage
    AXWindow::setCurrentScene(s);
    
    //Create a new entity called "blob"
    //(name, x, y, width, height)
    AXEntity* e = new AXEntity("blob", 10, 10, 10, 10);

    //add the entity to the scene
    s->addEntity(e);

    //return the window run, this is where the game will loop
    return AXWindow::run();

}