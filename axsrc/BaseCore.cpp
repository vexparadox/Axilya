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
    return window;
}

void BaseCore::setWindow(SDL_Window* w){
	if(w){
		window = w;
	}
}

BaseCore::~BaseCore(){
}

void BaseCore::exitCalled(){
	Runner::shutdown();
}
