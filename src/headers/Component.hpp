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
 * This is the base class of all Entity Components, it allows for event call backs and the game loop..
 */
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
    Transform* transform = 0;
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
    virtual void onCollision(Entity* e, int direction){};
    virtual void onWorldCollision(int direction){};
    virtual void onClick(int mouseButton){};
    virtual void onHover(){};
    virtual void onDestroy(){};
};

#endif /* Component_hpp */
