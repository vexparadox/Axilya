#ifndef World_hpp
#define World_hpp
#include "Tile.hpp"
#include <map>
class World{
    std::map<char, Tile*> tileTypes;
    void addTileType(char key, Tile* tile);
    Tile* getTileType(char key);
};

#endif
