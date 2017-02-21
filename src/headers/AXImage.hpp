//
//  AXImage.hpp
//  Axilya
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef AXImage_hpp
#define AXImage_hpp
#include <SDL2/SDL.h>
#include "glad.h"
#include "Vector2D.h"
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

class Runner;
class AXImage{
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    std::string path;
    int w = 0, h = 0;
    bool loaded = false;
    bool sdlLoad(const char* name);
    unsigned char* imageDataPtr = 0;
public:
    AXImage(){};
    ~AXImage();
    AXImage(std::string nameInput);
    //load the AXImage
    bool loadImage(std::string nameInput);
    
    //checks if files exists
    bool fileExists(const std::string& name);
    
    //various different draw methods
    void draw(const Math::Vector2D &v, float w, float h);
    void draw(float x, float y, float w, float h);
    void draw(const Math::Vector2D &v);
    void draw(float x, float y);
    
    //gets the width and height of the AXImage
    int getWidth();
    int getHeight();
    
    //attempts to grab the screen, not really working
    bool grabScreen(float x, float y, float w, float h);
    //returns if the AXImage is loaded
    bool isLoaded();
    //returns the path the file was loaded from
    std::string getPath();
};

#endif /* AXImage_hpp */
