#include "headers/AXTile.hpp"

AXTile::AXTile(int textureID) : texture(0), scene(0) {
    resourceManager = AXResourceManager::getInstance();
    texture = resourceManager->getTexture(textureID);
}

AXTile::AXTile(AXTexture* texture) : texture(0), scene(0){
    resourceManager = AXResourceManager::getInstance();
    if(texture){
        this->texture = texture;
    }
}

void AXTile::update() {
    for(auto c : components){
        c->update();
    }
}

void AXTile::draw(float x, float y, int w, int h) {
    if(texture) {
        AXGraphics::drawTexture(texture, x, y, w, h);
    }
}

void AXTile::addComponent(AXTileComponent* tileComponent) {
    if(tileComponent){
        components.push_back(tileComponent);
    }
}

void AXTile::setScene(AXScene *scene) {
    if(scene){
        this->scene = scene;
    }
}

AXScene* AXTile::getScene() {
    return scene;
}
