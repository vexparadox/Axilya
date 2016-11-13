//
// Created by William Meaton on 02/09/2016.
//

#include "Animator.hpp"
#include "Entity.hpp"

Animator::~Animator(){
    for(auto it = sprites.begin(); it != sprites.end(); it++){
       delete it->second;
    }
}

void Animator::addSprite(Sprite *s) {
    if(s) {
        sprites.insert(std::pair<std::string, Sprite *>(s->getName(), s));
        currentSprite = s;
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
        //make sure the colour is transparent
        Graphics::fill(255,255,255,255);
        currentSprite->draw(owner->getTransform()->getPos().x, owner->getTransform()->getPos().y, owner->getTransform()->getSize().x, owner->getTransform()->getSize().y);
    }else{
        if(owner->getDrawType() == AX_DRAW_RECT){
            Graphics::fill(colour);
            Graphics::drawRect(owner->getTransform()->getPos(), owner->getTransform()->getSize().x, owner->getTransform()->getSize().y);
        }else if(owner->getDrawType() == AX_DRAW_ELLIPSE){
            Graphics::fill(colour);
            Graphics::drawEllipse(owner->getTransform()->getPos().x+owner->getTransform()->getSize().x/2, 
                owner->getTransform()->getPos().y+owner->getTransform()->getSize().y/2
                , owner->getTransform()->getSize().x/2, owner->getTransform()->getSize().y/2);
        }
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

void Animator::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void Animator::setColour(float r, float g, float b){
    this->colour.set(r, g, b, 255);
}

void Animator::setColour(const Graphics::Colour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

Animator* Animator::clone(){
    Animator* a = new Animator();
    for(auto it = sprites.begin(); it != sprites.end(); it++){
        a->addSprite(it->second->clone());
    }
    a->currentSprite = this->currentSprite;
    a->colour = this->colour;
    return a;
}