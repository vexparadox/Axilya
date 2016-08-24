#include "World.hpp"
void World::addTile(char key, Tile* tile){
    tilePairs.insert(std::pair<char, Tile*>(key, tile));
}

Tile* World::getTile(char key){
    Tile* temp = 0;
    auto it = tilePairs.find(key);
    if(it != tilePairs.end()){
        temp = it->second;
    }
    return temp;
}