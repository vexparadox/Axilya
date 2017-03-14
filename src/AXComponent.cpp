//
//  AXComponent.cpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/AXComponent.hpp"
#include "headers/AXEntity.hpp"
#include "headers/AXTransform.hpp"
#include "headers/AXRenderer.hpp"

AXComponent::AXComponent(){
}

AXComponent::~AXComponent(){
}

AXEntity* AXComponent::getOwner(){
    return owner;
}

AXScene* AXComponent::getScene() {
    return owner->getScene();
}

void AXComponent::setOwner(AXEntity* o){
    this->owner = o;
    this->transform = owner->getTransform();
    this->renderer = owner->getRenderer();
}
