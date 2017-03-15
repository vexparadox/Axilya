//
// Created by William Meaton on 01/09/2016.
//

#include "headers/AXStaticWorld.hpp"
#include "headers/AXWindow.hpp"

AXStaticWorld::AXStaticWorld() {

}

void AXStaticWorld::loadTexture(int textureID) {
    if(resourceManager->getTexture(textureID)){
        texture = resourceManager->getTexture(textureID);
    }
}

void AXStaticWorld::loadTexture(AXTexture *t) {
    if(t){
        texture = t;
    }
}

void AXStaticWorld::draw() {
    if(texture) {
        AXGraphics::drawTexture(texture, 0, 0, AXWindow::getWidth(), AXWindow::getHeight());
    }
}

void AXStaticWorld::update() {

}
