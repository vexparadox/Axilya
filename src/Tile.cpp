#include "headers/Tile.hpp"

Tile::Tile(int textureID) : texture(0), scene(0) {
    resourceManager = ResourceManager::getInstance();
    texture = resourceManager->getTexture(textureID);
}

Tile::Tile(AXTexture* texture) : texture(0), scene(0){
    resourceManager = ResourceManager::getInstance();
    if(texture){
        this->texture = texture;
    }
}

void Tile::update() {
    for(auto c : components){
        c->update();
    }
}

void Tile::draw(float x, float y, int w, int h) {
    if(texture) {
        AXGraphics::drawTexture(texture, x, y, w, h);
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
