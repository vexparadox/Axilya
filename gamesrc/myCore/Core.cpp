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
    //setup the client
    Client::getInstance()->setup("178.62.6.47", 1234, 2, 0, 0);
    //connect it and only wait for 500ms
    Client::getInstance()->connect(200);
	if(Client::getInstance()->isConnected()){
		std::cout << "Connected succeded!" << std::endl;
	}

    setBackground(255, 255, 255, 255);
	//load in new textures!
	int image1ID = ResourceManager->addTexture("img.png");
	int image2ID = ResourceManager->addTexture("img2.png");
	//Create a new scene
	//scenes contain entities and worlds
	//scenes will update entities and worlds appropriately
	//this will in turn update components
	scene1 = new Scene();

	//Create a new entity
	//everything on screen is an entity
	//entites hold components like, colliders, rigidbodies, transforms and user made ones!
	//You can see below that Destroyable is a user made component, you can see what it does by looking in : myComponents/Destroyable.cpp
	character1 = new Entity("small_box", 200, 60, 20, 20); // Create a new entity with x, y, w, h
	character1->addComponent(new Destroyable()); // this is a custom component that allows this entity to be destroyed when clicked on
	character1->addRigidBody(true); // makes the object solid and react to physics
	character1->addCollider(new BoxCollider()); // Adds a simple box collider
	// character1->addTexture(image1ID); //add a texture that's been loaded into the resourceManager
	scene1->addEntity(character1); //add your entity to the scene

	//Start a new Entity
	character2 = new Entity("big_box", 100, 60, 50, 50); // Create a new entity with x, y, w, h
	character2->addRigidBody(new RigidBody(true)); // makes the object solid and react to physics
	character2->addCollider(new BoxCollider()); // Adds a simple box collider 
	character2->addComponent(new exampleComponent()); // This is a custom component that controls movement and colour changes
	// character2->addTexture(image2ID); //This is the same texture used for character1, but it's only been loaded once
	scene1->addEntity(character2); //add your entity to the scene
	//access custom components attached to the entity
	character2->getComponent<exampleComponent>()->x = 50;
}

void Core::update(){
	scene1->update();
}

void Core::draw(){
	scene1->draw();
} 
