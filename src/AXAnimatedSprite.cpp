//
// Created by William Meaton on 02/09/2016.
//

#include "headers/AXAnimatedSprite.hpp"

AXAnimatedSprite::~AXAnimatedSprite(){
    
}

AXAnimatedSprite::AXAnimatedSprite(int frameLength) : frameLength(frameLength), frameCount(0), texturePosition(0){

}

void AXAnimatedSprite::draw(float x, float y, float w, float h){
    AXGraphics::drawTexture(textures.at(texturePosition), x, y, w, h);
    frameCount++;
    if(frameCount > frameLength){
        frameCount = 0;
        if(texturePosition+1 < textures.size()){
            texturePosition++;
        }else{
            texturePosition = 0;
        }
    }
}

int AXAnimatedSprite::addTexture(const std::string &filename) {
    int id = resourceManager->addTexture(filename);
    if(id >= 0){
        textures.push_back(resourceManager->getTexture(id));
    }
    return id;
}


void AXAnimatedSprite::addTexture(int textureID) {
    textures.push_back(resourceManager->getTexture(textureID));
}

AXSprite* AXAnimatedSprite::clone(){
    AXAnimatedSprite* as = new AXAnimatedSprite(this->frameLength);
    for(auto& t : textures){
        as->addTexture(t->getID());
    }
    return as;
}
