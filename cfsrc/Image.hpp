//
//  Image.hpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include "SOIL/SOIL.h"
#include "GLFW/glfw3.h"
#include "Vector2D.h"
#include <iostream>
namespace Graphics{
class Image{
private:
    GLuint textureID;
    int w, h, mipMapLeveCount;
    bool loaded = false;
    GLuint getTextureID();
    void openGlLoad(const char* name);
public:
    Image(){};
    ~Image();
    Image(std::string nameInput);
    //load the image
    bool loadImage(std::string nameInput);
    
    //various different draw methods
    void draw(const Math::Vector2D &v, float w, float h);
    void draw(float x, float y, float w, float h);
    void draw(const Math::Vector2D &v);
    void draw(float x, float y);
    
    //gets the width and height of the image
    int getWidth();
    int getHeight();
    
    //attempts to grab the screen, not really working
    bool grabScreen(float x, float y, float w, float h);
    //returns if the image is loaded
    bool isLoaded();
};
}

#endif /* Image_hpp */
