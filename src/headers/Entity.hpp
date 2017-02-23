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
 * This class describes an Axilya Entity, all game objects are Entities in Axilya.
 * Entities are a collection of Components that update and draw, Transform and Renderer are attached by default.
 */

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>

#include "Math.h"
#include "ResourceManager.hpp"
#include "PrefabManager.hpp"
//components
#include "Components.h"
#include "Renderer.hpp"
#include "CollideDirections.hpp"
class Scene;
class Entity{
    //get an instance of the resourcemanager
    ResourceManager* resourceManager = ResourceManager::getInstance();

    //save the name of the entity
    std::string name;

    //if the entity is listed to be removed
    bool dead = false;

    //if the entity is active
    bool active = true;

    //the scene this entity belongs to
    Scene* scene = 0;

    //a list of standard components, these are presets
    Transform* transform = 0;
    Collider* collider = 0;
    RigidBody* rigidBody = 0;

    //the last collisions
    //the first two bytes are the screen bounds
    //the last 16 bytes are of entity collisions
    unsigned char lastCollisions[18];
    //used to temp store the current collisions
    unsigned char currentCollisions[18];

    //a list of custom components
    std::vector<Component*> components;

    //Renderer holds all of the drawing capabilities of the Entitity
    Renderer* renderer = 0;

    void handle_eptr(std::exception_ptr);
    //default to drawing rect
    int drawType = AX_DRAW_RECT;
public:
    //constructors
    Entity(const std::string& name, const Math::Vector2D& pos, const Math::Vector2D& size);
    Entity(const std::string& name, float x, float y, float w, float h);
    Entity(const std::string& name);
    ~Entity();

    //sets up components
    void start();
    //update and draws
    void update();
    void draw(const Math::Vector2D& renderOffset);

    //this method deletes all the data to do with this entity
    void destroy();
    
    void setDrawType(int type);
    int getDrawType();
    //moves the transform and any colliders attached by a certain amount
    void moveEntity(Math::Vector2D v);
    void moveEntity(float x, float y);
    //set and get the colour
    void setColour(float r, float g, float b, float a);
    void setColour(float r, float g, float b);
    void setColour(const AXGraphics::Colour &c);
    const AXGraphics::Colour& getColour();
    //set and get scene
    void setScene(Scene*);
    Scene* getScene();
    //get and set the active state of the entity
    void setActive(bool a);
    bool isActive();
    //check if the enitity should die
    bool isDead();
    //returns if the last thing it touched was the ground
    bool isGrounded();
    //add RigidBody
    void addRigidBody(RigidBody*);
    void addRigidBody(bool);
    //get the rigidBody
    RigidBody* getRigidBody();
    //when a collision happens
    void onCollision(Entity* e, int direction);

    void onWorldCollision(int direction);
    //when a click happens
    void onClick(int mouseButton);
    
    void onDestroy();
    //when it's being hovered
    void onHover();
    //add a collider
    void addCollider(Collider*);
    //get the collider
    Collider* getCollider();
    //add a new component
    void addComponent(Component*);
    //return the transform
    Transform* getTransform();
    //get the animator
    Renderer* getRenderer();
    //get the name of the entity
    std::string& getName();
    void setName(const std::string& name);

    Entity* clone();

    //gets a component from this entity
    template<typename T>
    T* getComponent(){
        for(auto& c : components){
            T* t;
            if((t = dynamic_cast<T*>(c))){
                return t;
            }
        }
        //will return null if there's no component found
        return 0;
    }
};

#endif
