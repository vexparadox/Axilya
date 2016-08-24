#include "World.hpp"
void World::addTile(char key, Tile* tile){
    tilePairs.insert(std::pair<char, Tile*>(key, tile));
}