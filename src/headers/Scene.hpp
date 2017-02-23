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
 * This is used as a collection of Entities and a World, AXWindow will call update and draw on this object.
 */
#ifndef Scene_hpp
#define Scene_hpp
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "World.hpp"
#include "pugixml.hpp"
#include "Math.h"

class Entity;
class Transform;
class Scene{
    //the vector of entities
    std::vector<Entity*> entities;
    World* world;
    Entity* gameMaster;
    Math::Vector2D renderOffset;
    std::unordered_map<std::string, Entity*> uMap;
public:
    Scene();
    ~Scene();
    
    void start();

    /*!
    * Called via the Core game loop. 
    * This will call Update on all Entities and thus Components 
    */
    void update();
    
    /*!
    * Called via the Core game loop.
    * This will call Draw on all Entities and thus Components 
    */
    void draw();
    /*!
    * Adds a new Entity to this Scene
    * @param e the new Entity being added
    * @return wheather it was succesful or not
    */

    Math::Vector2D& getRenderOffset();
    void offsetRenderer(float x, float y);
    void offsetRenderer(Math::Vector2D& v);
    void setRenderOffset(float x, float y);
    void setRenderOffset(Math::Vector2D& v);
    
    bool addEntity(Entity* e);

    bool setGameMaster(Entity* e);

    Entity* getGameMaster();

    void addWorld(World* w);

    void removeEntity(Entity* e);

    Entity* instantiate(const std::string& name, Entity* e, Transform* t);
    Entity* instantiate(const std::string& name, Entity* e);

    Entity* findEntity(const std::string& name);

    void collideCheck(Entity* e, Math::Vector2D& proposedMovement, unsigned char* colls);

    void parseSceneFile(const std::string& path);
    /*!
    * Returns the number of Entities in this Scene
    * @return number of Entities in the Scene vector
    */
    std::vector<Entity*>& getEntities();
    int numEntities();
};

#endif
