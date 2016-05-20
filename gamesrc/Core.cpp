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
	Runner::setActiveScene(scene1);
	
	Entity* e = new Entity(50, 50, 50 ,50);
	e->addComponent(new RigidBody(e, true));
	e->addTexture(new Image("img.png"));
	e->addCollider(new BoxCollider(e));
	scene1->addEntity(e);
	
	e = new Entity(300, 50, 50 ,50);
	e->addComponent(new RigidBody(e, true));
	e->addTexture(new Image("img.png"));
	e->addCollider(new BoxCollider(e));
	scene1->addEntity(e);
	
	e = new Entity(200, 60, 20, 20);
	e->addComponent(new RigidBody(e, true));
	e->addTexture(new Image("img.png"));
	e->addCollider(new BoxCollider(e));
	scene1->addEntity(e);
	
	std::cout << scene1->numEntities()<<std::endl;
	
}

void Core::update(){
	
}

void Core::draw(){

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