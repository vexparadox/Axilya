#include "Tile.hpp"

Tile::Tile(int textureID) {
    texture = resourceManager->getTexture(textureID);
}

void Tile::addComponent(TileComponent* tileComponent) {
    if(tileComponent){
        components.push_back(tileComponent);
    }
}