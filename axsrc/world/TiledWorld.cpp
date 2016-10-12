//
// Created by William Meaton on 01/09/2016.
//
#include "TiledWorld.hpp"

TiledWorld::TiledWorld(){
    isLoaded = false;
}

TiledWorld::~TiledWorld() {
    for(auto t : worldMatrix){
        delete t;
        t = 0;
    }
    worldMatrix.clear();
    for(auto t : tileTypes){
        delete t.second;
        t.second = 0;
    }
    tileTypes.clear();
}

void TiledWorld::loadWorld(const std::string &path, int tileSize) {

}

void TiledWorld::addTileType(char key, Tile* tile){
    tile->setScene(this->getScene());
    tileTypes.insert(std::pair<char, Tile*>(key, tile));
}

Tile* TiledWorld::getTileType(char key){
    Tile* temp = 0;
    auto it = tileTypes.find(key);
    if(it != tileTypes.end()){
        temp = it->second;
    }
    return temp;
}

void TiledWorld::draw(){
    for(auto t : worldMatrix){
//        t->draw()
    }
}

void TiledWorld::update(){
    for(auto t : worldMatrix){
        t->update();
    }
}