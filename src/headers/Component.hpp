//
//  Component.hpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include "ResourceManager.hpp"
#include "PrefabManager.hpp"
#include <stdio.h>
#include "Math.h"

class Entity;
class Scene;
class Component{
protected:
    //get an instance of the resourcemanager
    ResourceManager* resourceManager = ResourceManager::getInstance();
    PrefabManager* prefabManager = PrefabManager::getInstance();
    Entity* owner = 0;
    Component();
public:  
    virtual ~Component();
    //change what entity owns this component
    Entity* getOwner();
    //returns the owner's scene
    Scene* getScene();
    //returns what entity owns this component
    void setOwner(Entity*);
    //lets the components be cloned
    virtual Component* clone() = 0;
    //called at the begining of the program
    virtual void start(){};
    //a virutal update method that Component's can use
    virtual void update(){};
    virtual void onCollision(Entity* e){};
    virtual void onWorldCollision(int direction){};
    virtual void onClick(int mouseButton){};
    virtual void onHover(){};
    virtual void onDestroy(){};
};

#endif /* Component_hpp */
