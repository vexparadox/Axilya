#include "Tile.hpp"

Tile::Tile(int textureID) {
    texture = resourceManager->getTexture(textureID);
}

Tile::Tile(Texture* texture){
    if(texture){
        this->texture = texture;
    }
}

void Tile::update() {
    for(auto c : components){
        c->update();
    }
}

void Tile::draw(float x, float y) {
    if(texture) {
        texture->getImage()->draw(x, y);
    }
}

void Tile::addComponent(TileComponent* tileComponent) {
    if(tileComponent){
        components.push_back(tileComponent);
    }
}

void Tile::setScene(Scene *scene) {
    if(scene){
        this->scene = scene;
    }
}

Scene* Tile::getScene() {
    return scene;
}