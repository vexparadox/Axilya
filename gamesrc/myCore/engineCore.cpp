//
//  Core.cpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "engineCore.hpp"
//for graphics
using namespace Graphics;

void engineCore::setup(){
    //setup the client
    Client::getInstance()->setup("127.0.0.1", 1234, 2, 0, 0);
    Client::getInstance()->connect(200); //connect it and only wait for 200ms
	if(Client::getInstance()->isConnected()){ std::cout << "Connected succeded!" << std::endl; }

	//set the background color, transparent
	setBackground(255, 255, 255, 0);

	//Load the texture into the resourceManager
	tile1ID = resourceManager->addTexture("img.png");
	backgroundID = resourceManager->addTexture("img.png"); // this will simply return the value given to tile1ID

	//Create a new scene
	//scenes contain entities and worlds
	//scenes will update/draw entities and worlds appropriately
	scene1 = new Scene();
	//example of loading a SceneFile
	scene1->parseSceneFile("SceneFile.xml");
	//create and load a tiled world
	//tiled worlds have tiles which have components, like entities (collision, value holding etc)
	//you must load a CSV world file
	tileWorld = new TiledWorld();
	loadTiles();
    //NFI
	tileWorld->loadWorld("world1.csv", 64); // This line loads in the CSV file with a tilesize of 64 pixels


	//create and load a static world
	//static worlds are just background images drawn at the size of the window
	//they contain no logic
	staticWorld = new StaticWorld();
	staticWorld->loadTexture(backgroundID);

	//Create a new entity
	//everything on screen is an entity
	//entites hold components like, colliders, rigidbodies, transforms and user made ones!
	//You can see below that Destroyable is a user made component, you can see what it does by looking in : myComponents/Destroyable.cpp
	character1 = new Entity("small_box", 200, 200, 50, 50); // Create a new entity with name, x, y, w, h
	character1->addComponent(new Destroyable()); // this is a custom component that allows this entity to be destroyed when clicked on
	character1->addRigidBody(true); // makes the object solid and react to physics
	character1->addCollider(new BoxCollider()); // Adds a simple box collider
	character1->setColour(255, 0, 0, 255);
    character1->getAnimator()->addSprite(new StaticSprite("standing_box", "img2.png"));
	scene1->addEntity(character1); //add your entity to the scene

	//Start a new Entity
	//Entity names must be unique to the scene
	character2 = new Entity("big_box", 100, 60, 80, 80); // Create a new entity with name, x, y, w, h
	character2->addRigidBody(new RigidBody(true)); // makes the object solid and react to physics
	character2->addCollider(new BoxCollider()); // Adds a simple box collider
	character2->addComponent(new RigidBodyMove()); // This is a custom component that controls movement and colour changes
	scene1->addEntity(character2); //add your entity to the scene
	Entity* e = scene1->instantiate("big_box_clone", character2, new Transform(1, 1, 20, 20));
	character2->setActive(false);
    Runner::setCurrentScene(scene1);
}

void engineCore::loadTiles() {
    //create a new tile, pass it a textureID
    Tile* exampleTile = new Tile(tile1ID);
    //add a component to this tile
    exampleTile->addComponent(new exampleTileComponent());
	//When you load a tile you give it an identifier char
	//when this char is read in your world CSV, the corresponding tile will be placed in that spot of the world
    tileWorld->addTileType('1', exampleTile); // add the tile to the world
}