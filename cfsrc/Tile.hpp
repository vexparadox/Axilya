#ifndef Tile_hpp
#define Tile_hpp

#include "ResourceManager.hpp"
#include "TileComponent.hpp"
class Tile{
    ResourceManager* resourceManager = ResourceManager::getInstance();
    Texture* texture = 0;
    std::vector<TileComponent*> components;
public:
    Tile(int textureID);
    virtual void draw() = 0;
    virtual void update() = 0;
    void addComponent(TileComponent* tileComponent);
};
#endif // !Tile_hpp