//
//  Texture.h
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//
#include "Image.hpp"

class Texture{
    Graphics::Image* img = 0;
    int id = -1;
    public:
    Texture(int id, Graphics::Image* img) : id(id), img(img){}
    ~Texture(){ delete img; img = 0;}
    int getID(){ return id; }
    Graphics::Image* getImage(){ if(img) {return img;} else {return 0;} }
};