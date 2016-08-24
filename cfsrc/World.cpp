#include "World.hpp"
void World::addTileType(char key, Tile* tile){
    tileTypes.insert(std::pair<char, Tile*>(key, tile));
}

Tile* World::getTileType(char key){
    Tile* temp = 0;
    auto it = tileTypes.find(key);
    if(it != tileTypes.end()){
        temp = it->second;
    }
    return temp;
}