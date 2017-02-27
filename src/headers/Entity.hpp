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
    /*!
    * The constructor of an Entity
    *
    * @param name the name of this Entity, must be unique inside of it's Scene
    * @param pos a 2D vector defining the Entity's position (x, y)
    * @param size a 2D vector defining the Entity's size (w, h) 
    */ 
    Entity(const std::string& name, const Math::Vector2D& pos, const Math::Vector2D& size);
    /*!
    * The constructor of an Entity
    *
    * @param name the name of this Entity, must be unique inside of it's Scene
    * @param x the x position of the Entity
    * @param y the y position of the Entity
    * @param w the width of the Entity
    * @param h the height position of the Entity
    */ 
    Entity(const std::string& name, float x, float y, float w, float h);
    /*!
    * The constructor of an Entity that isn't going to be drawn
    *
    * This constructor will set the draw type to AX_DRAW_NONE
    * @param name the name of this Entity, must be unique inside of it's Scene
    */ 
    Entity(const std::string& name);
    /*!
    * The deconstructor of an Entity 
    *
    * This will destroy all Component's attached to this Entity including the default Transform and Renderer
    */ 
    ~Entity();

    /*!
    * A method that calls start() on all the Components attached to this Entity
    *
    * This method is called by the Scene at the start of the game loop 
    */ 
    void start();
    /*!
    * A method that calls update() on all the Components attached to this Entity
    *
    * This method is called by the Scene every frame of the game loop 
    */ 
    void update();
    /*!
    * A method that calls draw on the Renderer attached to this Entity
    *
    * This method is called by the Scene every frame of the game loop 
    * What the Renderer will draw is defined by the draw type and if there are any Sprites attached
    * @param renderOffset passed by the Scene to tell if Renderer if there's any offset applied to the drawing positions
    */ 
    void draw(const Math::Vector2D& renderOffset);

    /*!
    * A method that sets a flag for this Entity to be destroyed
    *
    * At the end of the frame that this method is called, the Scene will destroy this Entity 
    */ 
    void destroy();
    /*!
    * A method that sets a flag how this Entity should be drawn
    *
    * @param type can be AX_DRAW_RECT, AX_DRAW_ELLIPSE, AX_DRAW_NONE
    * @see EntityDrawTypes.hpp
    */ 
    void setDrawType(int type);

    /*!
    * A method that gets the flag how this Entity is being drawn
    *
    * @return The current draw type of this Entity
    * @see EntityDrawTypes.hpp
    */ 
    int getDrawType();
    /*!
    * A method that moves the Entity by a set amount
    *
    * This method also moves any Colliders attached
    * @param v the vector of movement that should be summed to the current position
    */ 
    void moveEntity(Math::Vector2D v);
    /*!
    * A method that moves the Entity by a set amount
    *
    * This method also moves any Colliders attached
    * @param x the x value of movement that should be summed to the current position
    * @param y the y value of movement that should be summed to the current position
    */ 
    void moveEntity(float x, float y);
    /*!
    * A method that sets the Colour that this Entity should be drawn at
    *
    * This doesn't take affect if there's a Sprite being drawn
    * This method is calling another in the Renderer
    * These values will be passed into a Colour object so will be clamped from 0-255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    * @param a the alpha value
    */ 
    void setColour(float r, float g, float b, float a);
    /*!
    * A method that sets the Colour that this Entity should be drawn at
    *
    * This doesn't take affect if there's a Sprite being drawn
    * This method is calling another in the Renderer
    * These values will be passed into a Colour object so will be clamped from 0-255
    * This method assumes the alpha value is 255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    */ 
    void setColour(float r, float g, float b);
    /*!
    * A method that sets the Colour that this Entity should be drawn at
    *
    * This doesn't take affect if there's a Sprite being drawn
    * This method is calling another in the Renderer
    * @param c the Colour object this will draw at 
    */ 
    void setColour(const AXGraphics::Colour &c);
    /*!
    * A method that gets the Colour that this Entity is being drawn at
    *
    * This method is calling another in the Renderer
    * @return the Colour object this Entity is being drawn at
    */ 
    const AXGraphics::Colour& getColour();
    /*!
    * A method to set the Scene that this Entity is in
    *
    * This method doesn't inform the Scene, it's called when you add an Entity to a Scene using Scene::addEntity()
    * @param s the Scene this Entity is being attached to
    */ 
    void setScene(Scene* s);
    /*!
    * A method to get the Scene that this Entity is in
    *
    * @return the Scene this Entity is attached to
    */ 
    Scene* getScene();
    /*!
    * A method to set if this Entity is active or not
    *
    * If an Entity isn't active it won't be drawn, updated or collidable
    * @param value if the Entity is active or not
    */ 
    void setActive(bool value);
    /*!
    * A method to get if this Entity is active or not
    *
    * If an Entity isn't active it won't be drawn, updated or collidable
    * @return if the Entity is active or not
    */ 
    bool isActive();
    /*!
    * A method to set if this Entity is marked to be destroyed or not
    *
    * This is set by the Entity::destroy()
    * @return if the Entity is going to be destroyed at the end of this frame
    */     
    bool isDead();
    /*!
    * A method to get if this Entity is grounded
    *
    * An Entity is grounded if the attached Collider has reported a bottom collision in the last frame
    * Will return false if there's no Collider attached
    * @return if this Entity is grounded
    */ 
    bool isGrounded();
    /*!
    * A method to add a RigidBody to this Entity
    *
    * This method will set the owner in the RigidBody
    * @param rb the RigidBody to attach
    */     
    void addRigidBody(RigidBody* rb);
    /*!
    * A method to add a RigidBody to this Entity
    *
    * This method will create a RigidBody for you
    * This method will set the owner in the RigidBody
    * @param gravity the created RigidBody's gravity value
    */
    void addRigidBody(bool gravity);
    /*!
    * A method to get the RigidBody attached to this Entity
    *
    * This method will return nullptr if there's not a RigidBody present
    * @return the attached RigidBody
    */
    RigidBody* getRigidBody();
    /*!
    * A method that calls onCollision on all Components attached to this Enitity
    *
    * This is called by the Scene when a collision occurs with another Entity
    * Catch this call inside of a Component
    * @param e the Entity that collided with this one
    * @param direction the direction of which the collision happened
    */
    void onCollision(Entity* e, int direction);
    /*!
    * A method that calls onWorldCollision on all Components attached to this Enitity
    *
    * This is called by the Scene when a collision occurs with the World or screen
    * Catch this call inside of a Component
    * @param direction the direction of which the collision happened
    */
    void onWorldCollision(int direction);
    /*!
    * A method that calls onClick on all Components attached to this Enitity
    *
    * This is called by the Collider when the it's clicked on
    * Catch this call inside of a Component
    * @param mouseButton the mouse button that was pressed
    */
    void onClick(int mouseButton);
    /*!
    * A method that calls onDestroy on all Components attached to this Enitity
    *
    * This is called by the Scene just before the Collider is destroyed
    * Catch this call inside of a Component
    */
    void onDestroy();
    /*!
    * A method that calls onHover on all Components attached to this Enitity
    *
    * This is called by the Collider when the mouse is over the Entity
    * Catch this call inside of a Component
    */
    void onHover();
    /*!
    * A method that adds a Collider to this Entity
    *
    * This method will set the owner in the Collider
    * @param coll the Collider to be attached
    */
    void addCollider(Collider* coll);

    /*!
    * A method that gets the Collider on this Entity
    *
    * @return the Collider that's attached
    */
    Collider* getCollider();
    /*!
    * A method that attaches a Component to this Entity
    *
    * The Components will be updated and called in the order that they're added
    * @param comp the Component to be attached
    */
    void addComponent(Component* comp);
    /*!
    * A method that gets the Transform attached to this Entity
    *
    * @return the Transform attache do this Entity
    */
    Transform* getTransform();
    /*!
    * A method that gets the Renderer attached to this Entity
    *
    * @return the Renderer attache do this Entity
    */
    Renderer* getRenderer();
    /*!
    * A method that gets the name of this Entity
    *
    * @return the name of this Entity
    */
    std::string& getName();
    /*!
    * A method that sets the name of this Entity
    *
    * @param name the name to set
    */
    void setName(const std::string& name);
    /*!
    * A method that returns a clone of this Entity
    *
    * This will call clone on all Components attached
    * @return a clone of this Entity
    */
    Entity* clone();

    /*!
    * A method to get a typed Component that's attached to this Entity
    *
    * This can be slow, store the result if using every frame
    * @return either nullptr or the found Component of the given Type
    */
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
