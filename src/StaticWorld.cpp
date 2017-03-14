//
// Created by William Meaton on 01/09/2016.
//

#include "headers/StaticWorld.hpp"
#include "headers/AXWindow.hpp"

StaticWorld::StaticWorld() {

}

void StaticWorld::loadTexture(int textureID) {
    if(resourceManager->getTexture(textureID)){
        texture = resourceManager->getTexture(textureID);
    }
}

void StaticWorld::loadTexture(AXTexture *t) {
    if(t){
        texture = t;
    }
}

void StaticWorld::draw() {
    if(texture) {
        AXGraphics::drawTexture(texture, 0, 0, AXWindow::getWidth(), AXWindow::getHeight());
    }
}

void StaticWorld::update() {

}
