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
    //loop entities and compare
    //pretty ineffcient
    for(int i = 0; i < entities.size(); i++){
        for(int j = 0; j < entities.size(); j++){
            //check they both have colliders
            if(!entities[i]->getCollider() || !entities[j]->getCollider()){
                break;
            }else{
                entities[i]->getCollider()->collisionColliderCheck(entities[j]->getCollider());
            }
        }
    }
}

void Scene::addEntity(Entity* e){
    e->setScene(this);
    this->entities.push_back(e);
}

int Scene::numEntities(){
    return this->entities.size();
}