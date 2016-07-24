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
        if(e->isActive()){
            e->draw();
        }
    }
}

void Scene::update(){
    for(auto e : entities){
        if(e->isActive()){
            e->update();
        }
    }
    //loop entities and compare
    //pretty ineffcient
}

void Scene::collideCheck(Entity* e, Math::Vector2D& proposedMovement){
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
		//    std::cout << "Collision occured" << std::endl;
		proposedMovement = e->getTransform()->getPos();
		break;
            }
        }
    }
}

void Scene::addEntity(Entity* e){
    e->setScene(this);
    this->entities.push_back(e);
}

void Scene::removeEntity(Entity* e){
    for(auto it = entities.begin(); it != entities.end(); it++){
        if(*it == e){
            entities.erase(it);
            break;
        }
    }
}

int Scene::numEntities(){
    return this->entities.size();
}
