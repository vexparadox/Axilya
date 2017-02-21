//
//  AXImage.cpp
//  Axilya
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "headers/AXImage.hpp"
#include "headers/AXWindow.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
AXImage::~AXImage(){
    SDL_FreeSurface(surface);
    stbi_image_free(imageDataPtr);
    SDL_DestroyTexture(texture);
}

AXImage::AXImage(std::string name){
    this->loadImage(name);
}

bool AXImage::fileExists (const std::string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}

bool AXImage::loadImage(std::string nameInput){
    path = nameInput;
    std::string temp = AXWindow::runPath+"data/" + nameInput;
    const char* name = temp.c_str();
    if(!fileExists(temp)){
        return false;
    }
    //check if it's already loaded, if so load into the same texture point
    if(loaded){
        //delete the texture and reload
        SDL_FreeSurface(surface);
        stbi_image_free(imageDataPtr);
        SDL_DestroyTexture(texture);
        texture = NULL;
        surface = NULL;
        //then load the texture
        sdlLoad(name);
    }
    loaded = sdlLoad(name);
    return loaded;
}

bool AXImage::sdlLoad(const char* name){
    int format = STBI_rgb_alpha;
    int formatFound;
    imageDataPtr = stbi_load(name, &this->w, &this->h, &formatFound, format);
    if(imageDataPtr == NULL){
        std::cout << stbi_failure_reason() << std::endl;
        return false;
    }
    surface = SDL_CreateRGBSurfaceWithFormatFrom(imageDataPtr, this->w, this->h, 32, 4*this->w, SDL_PIXELFORMAT_RGBA32);
    if (surface == NULL) {
        std::cout << SDL_GetError() << std::endl;
        stbi_image_free(imageDataPtr);
        return false;
    }
    texture = SDL_CreateTextureFromSurface(AXWindow::renderer, surface);
    if(texture == NULL){
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void AXImage::draw(float x, float y){
    this->draw(x, y, this->w, this->h);
}

void AXImage::draw(const Math::Vector2D &v){
    this->draw(v.x, v.y, this->w, this->h);
}

void AXImage::draw(const Math::Vector2D &v, float w, float h){
    this->draw(v.x, v.y, w, h);
}

void AXImage::draw(float x, float y, float width, float height){
    if(!loaded || texture == NULL || surface == NULL){
        std::cout << "No AXImage has been loaded" << std::endl;
        return;
    }
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = width;
    dest.h = height;
    if(SDL_RenderCopy(AXWindow::renderer, this->texture, NULL, &dest) != 0){
        std::cout << SDL_GetError() << std::endl;
    }
}

bool AXImage::grabScreen(float x, float y, float w, float h){
    return false;
}

bool AXImage::isLoaded(){
    return loaded;
}

std::string AXImage::getPath(){
    return path;
}
 
int AXImage::getHeight(){
    return h;
}

int AXImage::getWidth(){
    return w;
}
