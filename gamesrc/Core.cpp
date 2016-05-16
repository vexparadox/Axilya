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
	Entity* e = new Entity(Math::Vector2D(0,0));
	e->addComponent(new RigidBody(e));
	entities.push_back(e);
}

void Core::update(){
	for(auto e : entities){
		e->update();
	}
}

void Core::draw(){
	for(auto e : entities){
		e->draw();
	}
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