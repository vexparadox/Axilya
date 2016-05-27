#include "Entity.hpp"
#include "Runner.hpp"
#include "Scene.hpp"

Scene::Scene(){
}

Scene::~Scene(){
    for(auto e : entities){
        delete e;
        e = 0;
    }
}

void Scene::draw(){
    for(auto e : entities){
        e->draw();
    }
}

void Scene::update(){
    for(auto e : entities){
        e->update();
    }
}

void Scene::addEntity(Entity* e){
    e->setScene(this);
    this->entities.push_back(e);
}

int Scene::numEntities(){
    return this->entities.size();
}