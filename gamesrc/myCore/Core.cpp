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
	//load in new textures!
	int image1ID = ResourceManager->addTexture("img.png");
	int image2ID = ResourceManager->addTexture("img2.png");

	//Create a new scene
	//scenes contain entities and worlds
	//scenes will update entities and worlds appropriately
	//this will in turn update components
	scene1 = new Scene();
	character1 = new Entity(200, 60, 20, 20); // Create a new entity with x, y, w, h
	character1->addRigidBody(true); // makes the object solid and react to physics
	character1->addCollider(new BoxCollider()); // Adds a simple box collider
	character1->addTexture(image1ID); //add a texture that's been loaded into the ResourceManager
	character1->addComponent(new Destroyable()); // this is a custom component that allows this entity to be destroyed when clicked on
	scene1->addEntity(character1); //add your entity to the scene

	//Start a new Entity
	character2 = new Entity(100, 60, 50, 50); // Create a new entity with x, y, w, h
	character2->addRigidBody(new RigidBody(true)); // makes the object solid and react to physics
	character2->addCollider(new BoxCollider()); // Adds a simple box collider 
	character2->addComponent(new exampleComponent()); // This is a custom component that controls movement and colour changes
	character2->addTexture(image2ID); //This is the same texture used for character1, but it's only been loaded once
	scene1->addEntity(character2); //add your entity to the scene
}

void Core::update(){
	scene1->update();
}

void Core::draw(){
	scene1->draw();
} 