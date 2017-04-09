#include "headers/AXEntity.hpp"
#include "headers/AXWindow.hpp"
#include "headers/AXScene.hpp"
#include "headers/AXTransform.hpp"

AXScene::AXScene() : world(0), gameMaster(0){
    layers.reserve(18);
    for(int i = 0; i < 18; i++){
        std::vector<AXEntity*> t;
        layers.push_back(t);
    }
}

AXScene::~AXScene(){
   for(auto& l : layers){ 
       for(auto e : l){
           delete e;
           e = 0;
       }
    }
}

void AXScene::start(){
    if(gameMaster){
        gameMaster->start();
    }
    if(world){
        // this->world->start();
    }
    for(auto& l : layers){
        for(auto& e : l){
            e->start();
        }
    }
}

void AXScene::draw(){
    if(world) {
        this->world->draw();
    }
    for(auto& l : layers){
        for(auto& e : l){
            if(e->isActive() && !e->isDead()){
                e->draw(renderOffset);
            }
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
    for(auto& l : layers){
        for(auto& e : l){
            if(e->isActive() && !e->isDead()){
                e->update();
            }
        }
    }
    for(auto& l : layers){
        for(auto it = l.begin(); it != l.end(); it++){
            if((*it)->isDead()){
                entityMap.erase((*it)->getName());
                (*it)->onDestroy();
                l.erase(it);
                break;
            }
        }
    }
}

void AXScene::collideCheck(AXEntity* e, AXVector2D& proposedMovement, unsigned char* colls){
    //a collision counter to make sure it doesn't check past 4 entities 
    char collisions = 0;
    memset(colls, 0, 16);
    //if colliding on a specific layer
    if(e->getCollisionLayer() != -1){
        for(int j = 0; j < layers.size(); j++){
            for(int i = 0; i < layers[j].size(); i++){
                AXEntity* compE = layers[j][i];
                //if it's collided 4 times, stop
                if(collisions >= 3){
                    break;
                }
                if(compE->getCollider() && compE->isActive() && !compE->isDead() && compE->getCollisionLayer() == e->getCollisionLayer()){
                    //don't compare against the proposed
                    if(compE != e){
                        int j;
                        for(j = 0; j < 4; j++){
                            //get the result of the collision and save it
                            colls[j+(4*collisions)] = compE->getCollider()->checkMovement(e, proposedMovement);
                            //if it's dead 
                            if(colls[j+(4*collisions)] != 0){
                                compE->onCollision(e, colls[j+(4*collisions)]);
                                e->onCollision(compE, colls[j+(4*collisions)]);
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
    }else{
        for(int j = 0; j < layers.size(); j++){
            for(int i = 0; i < layers[j].size(); i++){
                AXEntity* compE = layers[j][i];
                //if it's collided 4 times, stop
                if(collisions >= 3){
                    break;
                }
                if(compE->getCollider() && compE->isActive() && !compE->isDead()){
                    //don't compare against the proposed
                    if(compE != e){
                        int j;
                        for(j = 0; j < 4; j++){
                            //get the result of the collision and save it
                            colls[j+(4*collisions)] = compE->getCollider()->checkMovement(e, proposedMovement);
                            //if it's dead 
                            if(colls[j+(4*collisions)] != 0){
                                compE->onCollision(e, colls[j+(4*collisions)]);
                                e->onCollision(compE, colls[j+(4*collisions)]);
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


bool AXScene::addEntity(AXEntity* e, int layer){
    if(e) {
        if(layer > 17){
            layer = 17;
        }
        if(layer < 0){
            layer = 0;
        }
        if(entityMap.find(e->getName()) == entityMap.end()) {
            e->setScene(this);
            e->setLayer(layer);
            this->layers[layer].push_back(e);
            this->entityMap[e->getName()] = e;
            return true;
        }else{
            AXLog::log("AXEntity name duplicate in scene", e->getName(), AX_LOG_ERROR);
            return false;
        }
    }else{
        return false;
    }
}

bool AXScene::addEntity(AXEntity* e){
    return addEntity(e, 0);
}
AXEntity* AXScene::instantiate(const std::string& name, AXEntity* e, AXTransform* t, int layer){
    if(e && t && name != ""){
        AXEntity* temp = e->clone();
        temp->getTransform()->set(t->getPosition(), t->getSize());
        if(temp->getCollider()){
            temp->getCollider()->getBounds()->set(t->getPosition(), t->getSize());
        }
        temp->setName(name);
        if(this->addEntity(temp, layer)){
            return temp;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

AXEntity* AXScene::instantiate(const std::string& name, AXEntity* e){
    return this->instantiate(name, e, e->getTransform(), e->getLayer());
}

void AXScene::setWorld(AXWorld *w) {
    if(w){
        world = w;
    }
}


AXEntity* AXScene::findEntity(const std::string &name) {
    if(entityMap.find(name) == entityMap.end()){
        AXLog::log("AXEntity not found using name", name, AX_LOG_WARNING);
        return 0;
    }else{
        return entityMap.at(name);
    }
}

std::vector<std::vector<AXEntity*> >& AXScene::getEntities(){
    return this->layers;    
}

int AXScene::numEntities(){
    int num = 0;
    for(auto& l : layers){
        num += l.size();
    }
    return num;
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
