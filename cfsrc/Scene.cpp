#include "Entity.hpp"
#include "Runner.hpp"
#include "Scene.hpp"

Scene::Scene(bool active) : active(active){
    Runner::addScene(this);
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

bool Scene::isActive(){
    return active;
}

void Scene::addEntity(Entity* e){
    this->entities.push_back(e);
}