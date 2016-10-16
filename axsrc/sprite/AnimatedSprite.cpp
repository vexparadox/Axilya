//
// Created by William Meaton on 02/09/2016.
//

#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(const std::string &name, int frameLength) : Sprite(name), frameLength(frameLength){

}

void AnimatedSprite::draw(float x, float y, float w, float h){
    textures.at(texturePosition)->getImage()->draw(x, y, w, h);
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

int AnimatedSprite::addTexture(const std::string &filename) {
    int id = resourceManager->addTexture(filename);
    if(id >= 0){
        textures.push_back(resourceManager->getTexture(id));
    }
    return id;
}


void AnimatedSprite::addTexture(int textureID) {
    textures.push_back(resourceManager->getTexture(textureID));
}

Sprite* AnimatedSprite::clone(){
    AnimatedSprite* as = new AnimatedSprite(this->getName(), this->frameLength);
    for(auto t : textures){
        as->addTexture(t->getID());
    }
    return as;
}