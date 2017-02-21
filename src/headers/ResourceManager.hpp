//
//  resourceManager.hpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef ResourceManager_h
#define ResourceManager_h

#include "AXTexture.h"
#include "AXFont.hpp"
#include <vector>
#include <unordered_map>
class AXTexture;
class AXFont;
class ResourceManager{
    ResourceManager(){}
    std::vector<AXTexture*> textures;
    std::vector<AXFont*> fonts;
    std::unordered_map<std::string, AXTexture*> textureMap;
    std::unordered_map<std::string, AXFont*> fontMap;
    static ResourceManager* instance;
    ~ResourceManager();
public:
    static ResourceManager* getInstance();
    //add a new AXTexture, will return -1 or new id
    int addTexture(const std::string&);
    int addFont(const std::string&);
    bool isTextureLoaded(const std::string&);
    bool isFontLoaded(const std::string&);
    AXFont* getFont(int);
    AXFont* getFont(const std::string&);
    AXTexture* getTexture(int);
    AXTexture* getTexture(const std::string&);
};

#endif
