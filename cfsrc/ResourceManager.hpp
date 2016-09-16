//
//  resourceManager.hpp
//  closedFrameworks
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
class ResourceManager{
    ResourceManager(){}
    std::vector<Texture*> textures;
    std::unordered_map<std::string, Texture*> textureMap;
    static ResourceManager* instance;
    ~ResourceManager();
    public:
    static ResourceManager* getInstance();
    //add a new texture, will return -1 or new id
    int addTexture(const std::string&);
    int addTexture(Graphics::Image*);
    bool isTextureLoaded(const std::string&);
    //gets a texture based on an id, allows 1 step access
    Texture* getTexture(int i);
    Texture* getTexture(const std::string& s);
};

#endif