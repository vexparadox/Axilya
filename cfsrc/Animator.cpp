//
// Created by William Meaton on 02/09/2016.
//

#include "Animator.hpp"
#include "Entity.hpp"

void Animator::addSprite(Sprite *s) {
    if(s) {
        sprites.insert(std::pair<std::string, Sprite *>(s->getName(), s));
    }
}

void Animator::setSprite(const std::string &name) {
    if(sprites.find(name) != sprites.end()){
        this->currentSprite = sprites.at(name);
    }
}

void Animator::setSprite(Sprite *s) {
    if(s){
        this->currentSprite = s;
    }
}

void Animator::draw() {
    if(currentSprite){
        Graphics::fill(255,255,255,255);
        currentSprite->draw(owner->getTransform()->getPos().x, owner->getTransform()->getPos().y, owner->getTransform()->getSize().x, owner->getTransform()->getSize().y);
    }else{
        Graphics::fill(colour);
        Graphics::drawRect(owner->getTransform()->getPos(), owner->getTransform()->getSize().x, owner->getTransform()->getSize().y);
    }
}

void Animator::setOwner(Entity *owner) {
    if(owner){
        this->owner = owner;
    }
}

Graphics::Colour& Animator::getColour() {
    return colour;
}
