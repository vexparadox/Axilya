//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>
int main(int argc, char const *argv[])
{
	AXWindow::init(720, 480, "Text Example", AX_DEFAULT);
	AXScene* scene = new AXScene();
	AXWindow::setCurrentScene(scene);
	// AXGraphics::setBackground(0, 0, 0, 255);
	//we can add a font file with the size 18
	//remember that all files are prefixed with the runpath + data/
	int fontID = AXResourceManager::getInstance()->addFont("Arial.ttf", 18);
	//lets make an AXEntity
	AXEntity* e = new AXEntity("text_entity", 0, 0, 0, 0); // The size of an AXEntity will be changed to fit the text you attach to it
	e->addCollider(new AXBoxCollider()); // Entities that display text can also have Colliders and Rigidbodies
	e->addRigidBody(true);
	//We give the make a AXStaticText with a string to show and a fontID to use
	// and then give it to the AXRenderer with a name
	//we can use this name later, this works the same as AXSprites
	AXStaticText staticText = new AXStaticText("This is an object with gravity and a collider!", fontID);
	e->getRenderer()->addText(staticText, "example_text");
	scene->addEntity(e);
	return AXWindow::run();
}