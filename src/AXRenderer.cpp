//
// Created by William Meaton on 02/09/2016.
//

#include "headers/AXRenderer.hpp"
#include "headers/AXEntity.hpp"
#include "headers/AXText.hpp"


AXRenderer::AXRenderer(){
     this->colour = AXColour(0, 0, 0, 255);
}

AXRenderer::~AXRenderer(){
    for(auto it = sprites.begin(); it != sprites.end(); it++){
       delete it->second;
    }
    for(auto it = texts.begin(); it != texts.end(); it++){
       delete it->second;
    }
}

void AXRenderer::addSprite(AXSprite *s) {
    if(s) {
        sprites.insert(std::pair<std::string, AXSprite *>(s->getName(), s));
        currentSprite = s;
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

void AXRenderer::addText(AXText* text){
    if(text){
        this->currentText = text;
        currentText->setOwner(owner);
        currentText->bakeText();
        this->setDrawType(AX_DRAW_TEXT);
        this->texts.insert(std::pair<std::string, AXText*>(text->getName(), text));
    }
}

void AXRenderer::setText(const std::string& name){
    if(texts.find(name) != texts.end()){
        this->currentText = texts.at(name);
        this->setDrawType(AX_DRAW_TEXT);
    }
}

int AXRenderer::getDrawType(){
    return drawType;
}

void AXRenderer::setDrawType(int type){
    this->drawType = type;
}

void AXRenderer::setSprite(const std::string &name) {
    if(sprites.find(name) != sprites.end()){
        this->currentSprite = sprites.at(name);
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

AXSprite* AXRenderer::getCurrentSprite(){
    return currentSprite;
}

void AXRenderer::draw(const AXVector2D& renderOffset) {
    AXVector2D position = owner->getTransform()->getPosition()+renderOffset;
    AXVector2D size = owner->getTransform()->getSize();
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

void AXRenderer::setOwner(AXEntity *owner) {
    if(owner){
        this->owner = owner;
    }
}

AXColour& AXRenderer::getColour() {
    return colour;
}

void AXRenderer::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void AXRenderer::setColour(float r, float g, float b){
    this->colour.set(r, g, b, 255);
}

void AXRenderer::setColour(const AXColour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

AXRenderer* AXRenderer::clone(){
    AXRenderer* a = new AXRenderer();
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
