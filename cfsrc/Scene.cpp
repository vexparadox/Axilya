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
}

void Scene::collideCheck(Entity* e, Math::Vector2D& proposedMovement){
    bool collide = false;
    proposedMovement += e->getTransform()->getPos();
    //check this entity against the rest with the proposedMovement
    for(int i = 0; i < entities.size(); i++){
        if(!entities[i]->getCollider()){
            break;
        }else{
            //don't compare against the proposed
            if(entities[i] == e){
                break;
            }
            //if there is a collision then allow it to correct and loop again
            if(entities[i]->getCollider()->checkMovement(e, proposedMovement)){
                collide = true;
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