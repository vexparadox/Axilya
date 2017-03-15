//
// Created by William Meaton on 01/09/2016.
//
#include "headers/AXTiledWorld.hpp"

AXTiledWorld::AXTiledWorld(int width, int height) : width(width), height(height){
    isLoaded = false;
}

AXTiledWorld::~AXTiledWorld() {
    for(auto& t : worldMatrix){
        delete t;
        t = 0;
    }
    worldMatrix.clear();
    for(auto& t : tileTypes){
        delete t.second;
        t.second = 0;
    }
    tileTypes.clear();
}

void AXTiledWorld::loadWorld(const std::string &path, int tileSize) {

}

void AXTiledWorld::addTileType(char key, AXTile* tile){
    tile->setScene(this->getScene());
    tileTypes.insert(std::pair<char, AXTile*>(key, tile));
}

AXTile* AXTiledWorld::getTileType(char key){
    AXTile* temp = 0;
    auto it = tileTypes.find(key);
    if(it != tileTypes.end()){
        temp = it->second;
    }
    return temp;
}

void AXTiledWorld::draw(){
//    for(auto& t : worldMatrix){
        //need to pass the x, y to the tile to draw
       // t->draw(w, h)
//    }
}

void AXTiledWorld::update(){
    for(auto& t : worldMatrix){
        t->update();
    }
}
