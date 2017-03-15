//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>

SDL_Texture* texture; // let's save the texture
AXVector2D size;

void update(){

}

void draw(){
	//draw the texture we got from the font data
	AXGraphics::drawSDLTexture(texture, 0, 0, size.x, size.y);
}

int main(int argc, char const *argv[]){	
	AXWindow::init(720, 480, "Text Raw", AX_DEFAULT, update, draw);
	//load the font
	AXFont font("Arial.ttf", 20);
	//make a red colour
	AXColour colour(255, 0, 0, 255);
	//bake a texture
	texture = font.bakeTexture("Hello world!", colour);
	size = font.getStringSize("Hello world!");
	return AXWindow::run();
}