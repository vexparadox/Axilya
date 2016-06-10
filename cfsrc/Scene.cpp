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
    for(int i = 0; i < entities.size(); i++){
        int j = i+1;
        for(;j < entities.size(); j++){
            //check they both have colliders
            if(!entities[i]->getCollider() || !entities[j]->getCollider()){
                break;
            }else{
                std::cout << "Collider detected on " << i << " and " << j << std::endl;
            }
        }
    }
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