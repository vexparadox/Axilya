//
//  Core.cpp
//  Axilya
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "engineCore.hpp"
//for graphics
using namespace Graphics;

void engineCore::setup(){
	//set the background color, transparent
	setBackground(255, 255, 255, 0);

	//Load the texture into the resourceManager
	tile1ID = resourceManager->addTexture("img.png");
	backgroundID = resourceManager->addTexture("img.png"); // this will simply return the value given to tile1ID

	//Create a new scene
	//scenes contain entities and worlds
	//scenes will update/draw entities and worlds appropriately
	scene1 = new Scene();

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
	barrier = new Entity("barrier", 200, 200, 50, 50); // Create a new entity with name, x, y, w, h
	barrier->addComponent(new Destroyable()); // this is a custom component that allows this entity to be destroyed when clicked on
	barrier->addCollider(new BoxCollider()); // Adds a simple box collider
	barrier->setColour(255, 0, 0); // setting a colour doesn't affect sprites
    // barrier->getAnimator()->addSprite(new StaticSprite("standing_box", "img2.png")); // this adds a new static sprite with the image of "img2.png" in the data folder
    //add your entity to the scene
	prefabManager->addPrefab(barrier);

	//lets make 12 barriers
	for(int i = 0; i < 12; i++){
		scene1->instantiate("barrier_clone_"+std::to_string(i), prefabManager->getPrefab("barrier"), new Transform(i*50, Runner::getHeight()/2, 20, 10));
	}

	//Start a new Entity
	//Entity names must be unique to the scene
	character2 = new Entity("player_box", 100, 60, 80, 80); // Create a new entity with name, x, y, w, h
	character2->addRigidBody(new RigidBody(true)); // makes the object solid and react to physics
	character2->addCollider(new BoxCollider()); // Adds a simple box collider
	character2->addComponent(new RigidBodyMove()); // This is a custom component that controls movement and colour changes


	//add character2 to the prefab manager
	prefabManager->addPrefab(character2);
	
	//create a copy of the "big_box" from the prefab manager and keep track of it with `e`
	Entity* e = scene1->instantiate("player_box_clone", prefabManager->getPrefab("player_box"), new Transform(1, 1, 60, 60));
	//lets check if it was successful
	// if(e){
		// any changes we make to e are seperate to the original copy of character2
		// e->setDrawType(EntityDrawType::RECT); // make e an Ellipse, defaults too a Rect
	// }

	//Setup our gameMaster
	//A gameMaster is no different to another Entity, it's just stored in a special place
	//we can get the gameMaster from the Scene, this means from any component
	//the gameMaster is never drawn, only updated
	//We use the gameMaster to "manage" the game state in the scene
	//gameManagers are never drawn
	//creating an entity with just a name implies it's a data-only entity, it will have a DrawType of NONE
	//there can only be one gameMaster per scene
	gameMaster = new Entity("game_manager");
	gameMaster->addComponent(new GameMaster());
	scene1->setGameMaster(gameMaster);

	//lets just print all the names in the scene
	for(auto &e : scene1->getEntities()){
		std::cout << e->getName() << std::endl;
	}
	
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
