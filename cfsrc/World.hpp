#ifndef World_hpp
#define World_hpp
#include "Tile.hpp"
#include <map>
class World{
    std::map<char, Tile*> tilePairs;
    void addTile(char key, Tile* tile);

};

#endif
