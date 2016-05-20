#include "Entity.hpp"
#include "Runner.hpp"
#include "Scene.hpp"

Scene::Scene(){
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
    this->entities.push_back(e);
}