//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>

AXTexture* texture; // let's save the texture

void update(){

}

void draw(){
	//draw the texture we got from the font data
	AXGraphics::drawTexture(texture, 0, 0);
}

int main(int argc, char const *argv[]){	
	AXWindow::init(720, 480, "Text Raw", AX_DEFAULT, update, draw);
	//load the font
	AXFont font("data/Arial.ttf", 20);
	//make a red colour
	AXColour colour(255, 0, 0, 255);
	//bake a texture
	texture = font.bakeTexture("Hello world!", colour);
	return AXWindow::run();
}