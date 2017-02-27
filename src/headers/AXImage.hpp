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
    /*!
   * The constructor of an AXImage with no image loaded
   */
    AXImage(){};
    /*!
   * The destructor of the AXImage
   *
   * This will destroy any image data loaded and the associated SDL structs
   */
    ~AXImage();
    /*!
   * The constructor of an AXImage which will load in an image
   * @param nameInput the path of an image file to load
   */
    AXImage(std::string nameInput);
    /*!
   * A method to load an image file
   * @param nameInput the path of an image file to load
   * @return If the image was loaded successfully
   */
    bool loadImage(std::string nameInput);
    /*!
   * A method to check if a file exists
   * @param name the path of the file to be checked
   * @return If the file exists on the system
   */    
   bool fileExists(const std::string& name);
    /*!
   * A method to draw the AXImage
   * @param v a 2D vector that holds the draw position (x, y)
   * @param w the width to draw the image
   * @param h the height to draw the image
   */        
    void draw(const Math::Vector2D &v, float w, float h);
    /*!
   * A method to draw the AXImage
   * @param x the x position to draw the image
   * @param y the y position to draw the image
   * @param w the width to draw the image
   * @param h the height to draw the image
   */        
    void draw(float x, float y, float w, float h);
    /*!
   * A method to draw the AXImage
   *
   * When no width and height are specified the image will be drawn at it's native resolution
   * @param v a 2D vector that holds the draw position (x, y)
   */   
    void draw(const Math::Vector2D &v);
    /*!
   * A method to draw the AXImage
   *
   * When no width and height are specified the image will be drawn at it's native resolution
   * @param x the x position to draw the image
   * @param y the y position to draw the image
   */   
    void draw(float x, float y);
    
    /*!
   * A method to get the width of the AXImage
   * @return the width of the loaded image
   */  
    int getWidth();
    /*!
   * A method to get the height of the AXImage
   * @return the height of the loaded image
   */  
    int getHeight();
    
    /*!
   * A method to grab the pixel data from the screen
   * This is not working
   */  
    bool grabScreen(float x, float y, float w, float h);
    /*!
   * A method to check if the AXImage has been loaded
   * @return If the image has been loaded
   */      
    bool isLoaded();
    /*!
   * A method to get the path of the loaded AXImage
   * @return The path of the loaded image
   */      
    std::string getPath();
};

#endif /* AXImage_hpp */