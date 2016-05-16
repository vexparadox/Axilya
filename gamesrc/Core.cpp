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
	e = new Entity(Math::Vector2D(0,0));
	e->addComponent(new RigidBody(e));
}

void Core::update(){
	e->update();
}

void Core::draw(){
	e->draw();
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