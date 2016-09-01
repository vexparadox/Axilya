#include "Entity.hpp"
#include "Runner.hpp"
#include "Scene.hpp"

Scene::Scene(){
}

Scene::~Scene(){
//    for(auto e : entities){
//        delete e;
//        e = 0;
//    }
}

void Scene::draw(){
    if(world) {
        this->world->draw();
    }
    for(auto e : entities){
        if(e->isActive()){
            e->draw();
        }
    }
}

void Scene::update() {
    if (world) {
        this->world->update();
    }
    for(auto e : entities){
        if(e->isActive()){
            e->update();
        }
    } 
    //loop through and delete dead ones
//    auto it = std::remove_if(entities.begin(), entities.end(), [this](Entity* e){return e->isDead();});
//    uMap.erase((*it)->getName());
//    entities.erase(it);
//    for(auto it = entities.begin(); it != entities.end();){
//        if(*it) {
//            if ((*it)->isDead()) {
//                entities.erase(it);
//                uMap.erase((*it)->getName());
//                delete *it;
//                *it = 0;
//            } else {
//                it++;
//            }
//        }else{
//            it++;
//        }
//    }
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
		       std::cout << "Collision occured" << std::endl;
		    // proposedMovement = e->getTransform()->getPos();m
		break;
            }
        }
    }
}

void Scene::addEntity(Entity* e){
    if(e) {
        if(uMap.find(e->getName()) == uMap.end()) {
            e->setScene(this);
            this->entities.push_back(e);
            this->uMap[e->getName()] = e;
            return;
        }else{
            std::cout << "Entity with the name: " << e->getName() << " already in this scene." << std::endl;
            return;
        }
    }
}


void Scene::addWorld(World *w) {
    if(w){
        world = w;
    }
}

void Scene::removeEntity(Entity* e){
    for(auto it = entities.begin(); it != entities.end(); it++){
        if(*it == e){
            entities.erase(it);
            uMap.erase(e->getName());
            break;
        }
    }
}

Entity* Scene::findEntity(const std::string &name) {
    if(uMap.find(name) == uMap.end()){
        std::cout << "Entity not found with name: " << name << ". Returning null" << std::endl;
        return 0;
    }else{
        return uMap.at(name);
    }
}

int Scene::numEntities(){
    return this->entities.size();
}
