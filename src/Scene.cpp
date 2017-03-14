#include "headers/AXEntity.hpp"
#include "headers/AXWindow.hpp"
#include "headers/Scene.hpp"
#include "headers/Transform.hpp"

Scene::Scene() : world(0), gameMaster(0){
}

Scene::~Scene(){
   for(auto e : entities){
       delete e;
       e = 0;
   }
   entities.clear();
}

void Scene::start(){
    if(gameMaster){
        gameMaster->start();
    }
    if(world){
        // this->world->start();
    }
    for(auto& e : entities){
        e->start();
    }
}

void Scene::draw(){
    if(world) {
        this->world->draw();
    }
    for(auto& e : entities){
        if(e->isActive() && !e->isDead()){
            e->draw(renderOffset);
        }
    }
}

void Scene::update() {
    if(gameMaster){
        gameMaster->update();
    }
    if (world) {
        this->world->update();
    }
    for(auto& e : entities){
        if(e->isActive() && !e->isDead()){
            e->update();
        }
    }
    for(auto it = entities.begin(); it != entities.end(); it++){
        if((*it)->isDead()){
            entityMap.erase((*it)->getName());
            (*it)->onDestroy();
            entities.erase(it);
            break;
        }
    }
}

void Scene::collideCheck(AXEntity* e, Math::Vector2D& proposedMovement, unsigned char* colls){
    //a collision counter to make sure it doesn't check past 4 entities 
    char collisions = 0;
    memset(colls, 0, 16);
    for(int i = 0; i < entities.size(); i++){
        //if it's collided 4 times, stop
        if(collisions >= 3){
            break;
        }
        if(entities[i]->getCollider() && entities[i]->isActive() && !entities[i]->isDead()){
            //don't compare against the proposed
            if(entities[i] != e){
                int j;
                for(j = 0; j < 4; j++){
                    //get the result of the collision and save it
                    colls[j+(4*collisions)] = entities[i]->getCollider()->checkMovement(e, proposedMovement);
                    //if it's dead 
                    if(colls[j+(4*collisions)] != 0){
                        entities[i]->onCollision(e, colls[j+(4*collisions)]);
                        e->onCollision(entities[i], colls[j+(4*collisions)]);
                    }else{
                        break;
                    }
                }
                //if there was any collisions at all, move the counter fowards
                if(j > 0){
                    collisions++;
                }
            }
        }
    }
}

bool Scene::setGameMaster(AXEntity* e){
    if(e){
        this->gameMaster = e;
        return true;
    }else{
        return false;
    }
}

AXEntity* Scene::getGameMaster(){
    return this->gameMaster;
}

bool Scene::addEntity(AXEntity* e){
    if(e) {
        if(entityMap.find(e->getName()) == entityMap.end()) {
            e->setScene(this);
            this->entities.push_back(e);
            this->entityMap[e->getName()] = e;
            return true;
        }else{
            std::cout << "AXEntity with the name: " << e->getName() << " already in this scene." << std::endl;
            return false;
        }
    }else{
        return false;
    }
}
AXEntity* Scene::instantiate(const std::string& name, AXEntity* e, Transform* t){
    if(e && t && name != ""){
        AXEntity* temp = e->clone();
        temp->getTransform()->set(t->getPosition(), t->getSize());
        if(temp->getCollider()){
            temp->getCollider()->getBounds()->set(t->getPosition(), t->getSize());
        }
        temp->setName(name);
        if(this->addEntity(temp)){
            return temp;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

AXEntity* Scene::instantiate(const std::string& name, AXEntity* e){
    return this->instantiate(name, e, e->getTransform());
}

void Scene::setWorld(World *w) {
    if(w){
        world = w;
    }
}

void Scene::removeEntity(AXEntity* e){
    for(auto it = entities.begin(); it != entities.end(); it++){
        if(*it == e){
            entities.erase(it);
            entityMap.erase(e->getName());
            break;
        }
    }
}

AXEntity* Scene::findEntity(const std::string &name) {
    if(entityMap.find(name) == entityMap.end()){
        std::cout << "AXEntity not found with name: " << name << ". Returning null" << std::endl;
        return 0;
    }else{
        return entityMap.at(name);
    }
}

std::vector<AXEntity*>& Scene::getEntities(){
    return this->entities;
}

int Scene::numEntities(){
    return this->entities.size();
}

Math::Vector2D& Scene::getRenderOffset(){
    return renderOffset;
}
void Scene::offsetRenderer(float x, float y){
    renderOffset.x += x;
    renderOffset.y += y;
}

void Scene::offsetRenderer(Math::Vector2D& v){
    renderOffset += v;
}
void Scene::setRenderOffset(float x, float y){
    renderOffset.x = x;
    renderOffset.y = y;
}
void Scene::setRenderOffset(Math::Vector2D& v){
    renderOffset = v;
}
