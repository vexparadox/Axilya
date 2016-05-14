//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Core.hpp"
//for graphics
using namespace Graphics;
Core::Core(){
	
}

Core::~Core(){
}

void Core::setup(){
    setBackground(255, 255, 255, 255);
}

void Core::update(){
}

void Core::draw(){
	fill(255, 0, 0);
	drawRect(mouseX, mouseY, 50, 50);
}

void Core::exitCalled(){
	std::exit(0);
}

void Core::keyPressed(int key){

}

void Core::keyReleased(int key){
}

void Core::mousePressed(int button){
}

void Core::mouseReleased(int button){
}