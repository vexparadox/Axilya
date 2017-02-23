/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This class is used to hold image data and the instructions to load from a plethora files.
 */
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