//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>

int x = 0;

void setup(){
    //called once
}

void update(){
    if(AXInput::getValue("D")){
        x++;
    }
}

void draw(){
    //using the AXGraphics namespace you can draw raw shapes, lines and points 
    AXGraphics::drawRect(x, 50, 50, 50);
}

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window setup, update, and draw methods
    if(!AXWindow::init(720, 480, "Custom Update Draw", AX_DEFAULT, setup, update, draw)){
        AXLog::log("Window failed to initialise", "Quitting", AX_LOG_ERROR);
    	return -1;
    }
    //return the window run, this is where the update and draw will be called
    return AXWindow::run();
}