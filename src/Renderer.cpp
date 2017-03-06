//
// Created by William Meaton on 02/09/2016.
//

#include "headers/Renderer.hpp"
#include "headers/Entity.hpp"
#include "headers/AXText.hpp"


Renderer::Renderer(){
     this->colour = AXGraphics::Colour(0, 0, 0, 255);
}

Renderer::~Renderer(){
    for(auto it = sprites.begin(); it != sprites.end(); it++){
       delete it->second;
    }
}

void Renderer::addSprite(Sprite *s) {
    if(s) {
        sprites.insert(std::pair<std::string, Sprite *>(s->getName(), s));
        currentSprite = s;
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

void Renderer::addText(AXText* text){
    if(text){
        this->currentText = text;
        currentText->setOwner(owner);
        currentText->bakeText();
        this->setDrawType(AX_DRAW_TEXT);
        this->texts.insert(std::pair<std::string, AXText*>(text->getName(), text));
    }
}

void Renderer::setText(const std::string& name){
    if(texts.find(name) != texts.end()){
        this->currentText = texts.at(name);
        this->setDrawType(AX_DRAW_TEXT);
    }
}
void Renderer::setText(AXText* text){
    if(text){
        this->currentText = text;
        currentText->setOwner(owner);
        currentText->bakeText();
        this->setDrawType(AX_DRAW_TEXT);
    }
}

int Renderer::getDrawType(){
    return drawType;
}

void Renderer::setDrawType(int type){
    this->drawType = type;
}

void Renderer::setSprite(const std::string &name) {
    if(sprites.find(name) != sprites.end()){
        this->currentSprite = sprites.at(name);
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

void Renderer::setSprite(Sprite *s) {
    if(s){
        this->currentSprite = s;
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

Sprite* Renderer::getCurrentSprite(){
    return currentSprite;
}

void Renderer::draw(const Math::Vector2D& renderOffset) {
    Math::Vector2D position = owner->getTransform()->getPosition()+renderOffset;
    Math::Vector2D size = owner->getTransform()->getSize();
    //if there's a sprite
    int drawType = owner->getDrawType();
    if(drawType == AX_DRAW_SPRITE && currentSprite){
        //make sure the colour is transparent
        AXGraphics::fill(255,255,255, 0);
        currentSprite->draw(position.x, position.y, size.x, size.y);
    }else if(drawType == AX_DRAW_TEXT && currentText){
        //if there's a text
        currentText->draw(position.x, position.y);
    }else{
        //if it's set to shapes
        AXGraphics::fill(colour);
        if(drawType == AX_DRAW_RECT){
            AXGraphics::drawRect(position.x, position.y, size.x, size.y);
        }else if(drawType == AX_DRAW_ELLIPSE){
            AXGraphics::drawEllipse(position.x+size.x/2, position.y+size.y/2, size.x/2, size.y/2);
        }
    }
}

void Renderer::setOwner(Entity *owner) {
    if(owner){
        this->owner = owner;
    }
}

AXGraphics::Colour& Renderer::getColour() {
    return colour;
}

void Renderer::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void Renderer::setColour(float r, float g, float b){
    this->colour.set(r, g, b, 255);
}

void Renderer::setColour(const AXGraphics::Colour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

Renderer* Renderer::clone(){
    Renderer* a = new Renderer();
    for(auto it = sprites.begin(); it != sprites.end(); it++){
        a->addSprite(it->second->clone());
    }
    if(this->currentSprite){
        a->setSprite(this->currentSprite->getName());
    }
    if(this->currentText){
        a->addText(currentText->clone());
    }
    a->setDrawType(this->drawType);
    a->colour = this->colour;
    return a;
}
