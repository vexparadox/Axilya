//
//  BaseCore.cpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "BaseCore.hpp"
#include "Runner.hpp"

SDL_Window* BaseCore::getWindow(){
	return Runner::getWindow();
}

BaseCore::~BaseCore(){
}

void BaseCore::exitCalled(){
	Runner::shutdown();
}

int BaseCore::windowHeight(){
	return Runner::getHeight();
}

int BaseCore::windowWidth(){
	return Runner::getWidth();
}