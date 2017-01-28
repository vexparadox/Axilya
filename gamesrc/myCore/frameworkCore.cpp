//
//  frameworkCore.cpp
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "frameworkCore.hpp"
//for graphics
using namespace Graphics;

void frameworkCore::setup(){
	AXString str("hello");
}

void frameworkCore::update(){

}

void frameworkCore::draw(){
	//here is where we can draw things
	fill(255, 0, 0);
	drawRect(20, 20, 20, 20);
}