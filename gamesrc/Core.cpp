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
	scene1 = new Scene();

	//Start a new Entity
	character = new Entity(200, 60, 20, 20); // Create a new entity with x, y, w, h
	character->addRigidBody(true); // makes the object solid and react to physics
	// character->addTexture(""); add a texture if you like
	character->addCollider(new BoxCollider(character)); // Adds a simple box collider 
	character->addComponent(new exampleComponent(character)); // This is a custom component!
	scene1->addEntity(character); //add your entity to the scene
}

void Core::update(){
	scene1->update();
}

void Core::draw(){
	scene1->draw();
}

void Core::exitCalled(){
	std::exit(0);
}
  
void Core::mousePressed(int button){
	
}

void Core::mouseReleased(int button){
	
}