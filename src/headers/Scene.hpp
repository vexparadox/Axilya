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
    std::unordered_map<std::string, Entity*> entityMap;
public:
    /*!
    * The constructor of a Scene
    */
    Scene();
    /*!
    * The deconstructor of a Scene
    *
    * This will release all Entities in the scene
    */
    ~Scene();
    /*!
    * A method to start all Entity's and therefore Component's in the Scene
    *
    * This method is called once by the AXWindow
    */
    void start();
    /*!
    * A method to update all Entity's and therefore Component's in the Scene
    *
    * This method is called every frame by the AXWindow
    */
    void update();
    
    /*!
    * A method to draw all Entity's and therefore Renderer's in the Scene
    *
    * This method is called every frame by the AXWindow
    */
    void draw();
    /*!
    * A method to get the Renderer offset
    *
    * @return the vector of how the Renderer is being offset
    */
    Math::Vector2D& getRenderOffset();
    /*!
    * A method to add to the Renderer offset
    *
    * @param x how much to offset in the x axis
    * @param y how much to offset in the y axis
    */
    void offsetRenderer(float x, float y);
    /*!
    * A method to add to the Renderer offset
    *
    * @param v how much to offset the Renderer (x, y)
    */
    void offsetRenderer(Math::Vector2D& v);
    /*!
    * A method to set the Renderer offset
    *
    * @param x the offset to set in the x axis
    * @param y the offset to set in the y axis
    */
    void setRenderOffset(float x, float y);
    /*!
    * A method to set the Renderer offset
    *
    * @param v a vector to set the offset to (x, y)
    */
    void setRenderOffset(Math::Vector2D& v);
    /*!
    * A method to add an Entity to this Scene
    *
    * @param e the Entity to add
    * @return if the Entity was added successfully
    */
    bool addEntity(Entity* e);
    /*!
    * A method to set the GameMaster in this Scene
    *
    * The GameMaster is a special Entity that isn't drawn and is only updated, it's used to control game states.
    * @param e the Entity to set the GameMaster
    * @return if the GameMaster was set successfully
    */
    bool setGameMaster(Entity* e);
    /*!
    * A method to get the GameMaster in this Scene
    *
    * The GameMaster is a special Entity that isn't drawn and is only updated, it's used to control game states.
    * @return the GameMaster
    */
    Entity* getGameMaster();
    /*!
    * A method to set the World of this Scene
    *
    * @param w the world to set
    */
    void setWorld(World* w);
    /*!
    * A method to remove a specific Entity
    *
    * It's better to use the destroy() method on an Entity
    * @param e the entity to destroy
    */
    void removeEntity(Entity* e);
    /*!
    * A method to instantiate a new Entity in this Scene
    *
    * Instatniated Entity's will be put straight into the Scene
    * @param name the name of this new Entity
    * @param e the Entity this new one will copy
    * @param t a new Transform for this new Entity to be given
    * @return a pointer to the new Entity
    */
    Entity* instantiate(const std::string& name, Entity* e, Transform* t);
    /*!
    * A method to instantiate a new Entity in this Scene
    *
    * Instatniated Entity's will be put straight into the Scene
    * @param name the name of this new Entity
    * @param e the Entity this new one will copy
    * @return a pointer to the new Entity
    *
    * Without a seperate Transform this new Entity will get a copy of @param e's
    */
    Entity* instantiate(const std::string& name, Entity* e);
    /*!
    * A method to find an Entity in this scene
    *
    * @param name the name of the Entity to find
    * @return a pointer to the found Entity or nullptr
    */
    Entity* findEntity(const std::string& name);
    /*!
    * A method to check collisions of an Entity against all over in this Scene
    *
    * @param e the Entity to check
    * @param proposedMovement the vector of movement being attempted by @param e
    * @param colls an array of collision directions that will be filled by the Collider's
    */
    void collideCheck(Entity* e, Math::Vector2D& proposedMovement, unsigned char* colls);
    /*!
    * A method to parse a Scene XML file 
    *
    * This method is deprecated and isn't functional
    */
    void parseSceneFile(const std::string& path);
    /*!
    * Returns the number of Entities in this Scene
    * @return number of Entities in the Scene vector
    */
    std::vector<Entity*>& getEntities();
    int numEntities();
};

#endif
