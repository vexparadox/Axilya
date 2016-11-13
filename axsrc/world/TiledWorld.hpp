//
// Created by William Meaton on 01/09/2016.
//

#ifndef TiledWorld_hpp
#define TiledWorld_hpp

#include "World.hpp"
#include "Tile.hpp"
#include <unordered_map>

class TiledWorld : public World {
    //tile types loaded into the world
    std::unordered_map<char, Tile*> tileTypes;
    std::vector<Tile*> worldMatrix;
    bool isLoaded;

public:
    ~TiledWorld();
    TiledWorld();
    //allows the user to add a new tile type
    void addTileType(char key, Tile* tile);
    //returns a tile type based on a char
    Tile* getTileType(char key);
    //load a world in the data path, CSV
    void loadWorld(const std::string& path, int tileSize);
    virtual void draw();
    virtual void update();
};


#endif //Axilya_TILEDWORLD_H
