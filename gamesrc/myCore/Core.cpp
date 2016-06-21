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

void Core::setup(){
    setBackground(255, 255, 255, 255);
	//Create a new scene
	//scenes contain entities and worlds
	//scenes will update entities and worlds appropriately
	//this will in turn update components
	scene1 = new Scene();

	//Start a new Entity
	character = new Entity(300, 60, 20, 20); // Create a new entity with x, y, w, h
	character->addRigidBody(true); // makes the object solid and react to physics
	// character->addTexture(""); //add a texture if you like
	character->addCollider(new BoxCollider(character)); // Adds a simple box collider 
	character->addComponent(new exampleComponent(character)); // This is a custom component!
	scene1->addEntity(character); //add your entity to the scene
	
	character = new Entity(200, 60, 60, 200); // Create a new entity with x, y, w, h
	character->addRigidBody(false); // makes the object solid and react to physics
	// character->addTexture(""); //add a texture if you like
	character->addCollider(new BoxCollider(character)); // Adds a simple box collider 
	// character->addComponent(new exampleComponent(character)); // This is a custom component!
	scene1->addEntity(character); //add your entity to the scene

}

void Core::update(){
	scene1->update();
}

void Core::draw(){
	scene1->draw();
} 