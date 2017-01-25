#ifndef Tile_hpp
#define Tile_hpp

#include "../ResourceManager.hpp"
#include "TileComponent.hpp"
class Texture;
class Tile{
    ResourceManager* resourceManager = ResourceManager::getInstance();
    Texture* texture = 0;
    Scene* scene = 0;
    std::vector<TileComponent*> components;
public:
    Tile(int textureID);
    Tile(Texture* texture);
    void draw(float x, float y, int w, int h);
    void update();
    void setScene(Scene* scene);
    Scene* getScene();
    void addComponent(TileComponent* tileComponent);
};
#endif // !Tile_hpp