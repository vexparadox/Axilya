//
//  Texture.h
//  Project2
//
//  Created by William Meaton on 21/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//
#include "AXImage.hpp"

class AXTexture{
	AXImage* img = 0;
    int id = -1;
public:
    AXTexture(int id, AXImage* img) : id(id), img(img){}
    ~AXTexture(){ delete img; img = 0;}
    int getID(){ return id; }
	AXImage* getImage(){ if(img) {return img;} else {return 0;} }
};