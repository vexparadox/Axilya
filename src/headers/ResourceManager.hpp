//
//  resourceManager.hpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef ResourceManager_h
#define ResourceManager_h

#include "Texture.h"
#include <vector>
#include <unordered_map>
class Texture;
class AXFont;
class ResourceManager{
    ResourceManager(){}
    std::vector<Texture*> textures;
    std::vector<AXFont*> fonts;
    std::unordered_map<std::string, Texture*> textureMap;
    std::unordered_map<std::string, AXFont*> fontMap;
    static ResourceManager* instance;
    ~ResourceManager();
public:
    static ResourceManager* getInstance();
    //add a new texture, will return -1 or new id
    int addTexture(const std::string&);
    int addFont(const std::string&);
    bool isTextureLoaded(const std::string&);
    bool isFontLoaded(const std::string&);
    AXFont* getFont(int);
    AXFont* getFont(const std::string&);
    Texture* getTexture(int);
    Texture* getTexture(const std::string&);
};

#endif
