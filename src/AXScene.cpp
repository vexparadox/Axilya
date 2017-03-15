#include "headers/AXEntity.hpp"
#include "headers/AXWindow.hpp"
#include "headers/AXScene.hpp"
#include "headers/AXTransform.hpp"

AXScene::AXScene() : world(0), gameMaster(0){
}

AXScene::~AXScene(){
   for(auto e : entities){
       delete e;
       e = 0;
   }
   entities.clear();
}

void AXScene::start(){
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

void AXScene::draw(){
    if(world) {
        this->world->draw();
    }
    for(auto& e : entities){
        if(e->isActive() && !e->isDead()){
            e->draw(renderOffset);
        }
    }
}

void AXScene::update() {
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

void AXScene::collideCheck(AXEntity* e, AXVector2D& proposedMovement, unsigned char* colls){
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

bool AXScene::setGameMaster(AXEntity* e){
    if(e){
        this->gameMaster = e;
        return true;
    }else{
        return false;
    }
}

AXEntity* AXScene::getGameMaster(){
    return this->gameMaster;
}

bool AXScene::addEntity(AXEntity* e){
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
AXEntity* AXScene::instantiate(const std::string& name, AXEntity* e, AXTransform* t){
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

AXEntity* AXScene::instantiate(const std::string& name, AXEntity* e){
    return this->instantiate(name, e, e->getTransform());
}

void AXScene::setWorld(World *w) {
    if(w){
        world = w;
    }
}

void AXScene::removeEntity(AXEntity* e){
    for(auto it = entities.begin(); it != entities.end(); it++){
        if(*it == e){
            entities.erase(it);
            entityMap.erase(e->getName());
            break;
        }
    }
}

AXEntity* AXScene::findEntity(const std::string &name) {
    if(entityMap.find(name) == entityMap.end()){
        std::cout << "AXEntity not found with name: " << name << ". Returning null" << std::endl;
        return 0;
    }else{
        return entityMap.at(name);
    }
}

std::vector<AXEntity*>& AXScene::getEntities(){
    return this->entities;
}

int AXScene::numEntities(){
    return this->entities.size();
}

AXVector2D& AXScene::getRenderOffset(){
    return renderOffset;
}
void AXScene::offsetRenderer(float x, float y){
    renderOffset.x += x;
    renderOffset.y += y;
}

void AXScene::offsetRenderer(AXVector2D& v){
    renderOffset += v;
}
void AXScene::setRenderOffset(float x, float y){
    renderOffset.x = x;
    renderOffset.y = y;
}
void AXScene::setRenderOffset(AXVector2D& v){
    renderOffset = v;
}
