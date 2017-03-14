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
 * This is the base class of all AXEntity Components, it allows for event call backs and the game loop..
 */
#ifndef Component_hpp
#define Component_hpp

#include "ResourceManager.hpp"
#include "PrefabManager.hpp"
#include <stdio.h>
#include "AXMath.hpp"

class AXEntity;
class Scene;
class Transform;
class Renderer;
class Component{
protected:
    ResourceManager* resourceManager = ResourceManager::getInstance();
    PrefabManager* prefabManager = PrefabManager::getInstance();
    /*!
    * The AXEntity that owns this Component
    */ 
    AXEntity* owner = 0;
    /*!
    * The Transform that's attached to the AXEntity that owns this Component
    */ 
    Transform* transform = 0;
    /*!
    * The Renderer that's attached to the AXEntity that owns this Component
    */ 
    Renderer* renderer = 0;
    Component();
public:
    /*!
    * The virtual deconstructor of this Component.
    *
    * Implement your own in the CustomComponent<custom>
    */ 
    virtual ~Component();
    /*!
    * A method to get the AXEntity that owns this Component.
    *
    * @return the owner of this Component
    */ 
    AXEntity* getOwner();
    /*!
    * A method to get the Scene that the owner of this Component is in.
    *
    * @return the the scene that the owner of this Component is in 
    */ 
    Scene* getScene();
    /*!
    * A method to set the AXEntity that owns this Component.
    *
    * This is called when the Component is added to an AXEntity
    * @param e the entity to set
    */ 
    void setOwner(AXEntity* e);
    /*!
    * A virtual method that returns a clone of this Component.
    *
    * Implement your own when inheriting from Component, this is done automatically if you use CustomComponent< custom > 
    * @return a clone of this Component
    */ 
    virtual Component* clone() = 0;
    /*!
    * A virtual method that is called at the start of the game loop.
    */ 
    virtual void start(){};
    /*!
    * A virtual method that is called every frame in the game loop.
    */    
    virtual void update(){};
    /*!
    * A virtual method that is called if a Collider is present and a collision happens with another AXEntity.
    * @param e the AXEntity that has collided with this one
    */    
    virtual void onCollision(AXEntity* e){};
    /*!
    * A virtual method that is called if a Collider is present and a collision happens with another AXEntity.
    * @param e the AXEntity that has collided with this one
    * @param direction the direction that the collision occured AX_COLLIDE_UP/DOWN/RIGHT/LEFT
    */
    virtual void onCollision(AXEntity* e, int direction){};
    /*!
    * A virtual method that is called if a Collider is present and a collision happens with the World or Screen.
    * @param direction the direction that the collision occured AX_COLLIDE_UP/DOWN/RIGHT/LEFT
    */
    virtual void onWorldCollision(int direction){};
    /*!
    * A virtual method that is called if a Collider is present the AXEntity is clicked on.
    * @param mouseButton the mouse button that's pressed 0, 1, 2
    */
    virtual void onClick(int mouseButton){};
    /*!
    * A virtual method that is called if a Collider is present the AXEntity is hovered over.
    */
    virtual void onHover(){};
    /*!
    * A virtual method that is called just before the AXEntity this Component is attached to is destroyed.
    */
    virtual void onDestroy(){};
};

#endif /* Component_hpp */
