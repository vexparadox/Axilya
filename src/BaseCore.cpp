//
//  BaseCore.cpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "headers/BaseCore.hpp"
#include "headers/AXWindow.hpp"

BaseCore::BaseCore(){
    resourceManager = ResourceManager::getInstance();
    prefabManager = PrefabManager::getInstance();
}


BaseCore::~BaseCore(){

}

SDL_Window* BaseCore::getWindow(){
	return AXWindow::getWindow();
}


void BaseCore::exitCalled(){
	AXWindow::shutdown();
}

int BaseCore::windowHeight(){
	return AXWindow::getHeight();
}

int BaseCore::windowWidth(){
	return AXWindow::getWidth();
}

int BaseCore::displayWidth(){
	return AXWindow::getDisplayWidth();
}

int BaseCore::displayHeight(){
	return AXWindow::getDisplayHeight();
}
