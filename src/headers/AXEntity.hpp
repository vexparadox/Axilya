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
* This class describes an Axilya AXEntity, all game objects are Entities in Axilya.
* Entities are a collection of Components that update and draw, AXTransform and AXRenderer are attached by default.
*/
#ifndef AXEntity_hpp
#define AXEntity_hpp

#include <stdio.h>

#include "AXMath.hpp"
#include "AXResourceManager.hpp"
#include "AXPrefabManager.hpp"
//components
#include "AXComponents.h"
#include "AXLog.hpp"
#include "AXRenderer.hpp"
#include "AXAudioPlayer.hpp"
#include "AXCollideDirections.hpp"
class AXScene;
class AXEntity{
    //get an instance of the resourcemanager
    AXResourceManager* resourceManager = AXResourceManager::getInstance();

    //save the name of the entity
    std::string name;

    //if the entity is listed to be removed
    bool dead = false;

    //if the entity is active
    bool active = true;

    //the scene this entity belongs to
    AXScene* scene = 0;
    //the AXScene layer this entity is in
    int layer = 0;
    int collisionLayer = -1;

    //a list of standard components, these are presets
    AXTransform* transform = 0;
    AXCollider* collider = 0;
    AXRigidBody* rigidBody = 0;

    //the last collisions
    //the first two bytes are the screen bounds
    //the last 16 bytes are of entity collisions
    unsigned char lastCollisions[18];
    //used to temp store the current collisions
    unsigned char currentCollisions[18];

    //a list of custom components
    std::vector<AXComponent*> components;

    //AXRenderer holds all of the drawing capabilities of the AXEntity
    AXRenderer* renderer = 0;

    //AXAudioPlayer holds the audio play back methods fo this AXEntity
    AXAudioPlayer* audioPlayer = 0;

    void handle_eptr(std::exception_ptr);
public:
    /*!
    * The constructor of an AXEntity
    *
    * @param name the name of this AXEntity, must be unique inside of it's AXScene
    * @param pos a 2D vector defining the AXEntity's position (x, y)
    * @param size a 2D vector defining the AXEntity's size (w, h) 
    */ 
    AXEntity(const std::string& name, const AXVector2D& pos, const AXVector2D& size);
    /*!
    * The constructor of an AXEntity
    *
    * @param name the name of this AXEntity, must be unique inside of it's AXScene
    * @param x the x position of the AXEntity
    * @param y the y position of the AXEntity
    * @param w the width of the AXEntity
    * @param h the height position of the AXEntity
    */ 
    AXEntity(const std::string& name, float x, float y, float w, float h);
    /*!
    * The constructor of an AXEntity that isn't going to be drawn
    *
    * This constructor will set the draw type to AX_DRAW_NONE
    * @param name the name of this AXEntity, must be unique inside of it's AXScene
    */ 
    AXEntity(const std::string& name);
    /*!
    * The deconstructor of an AXEntity 
    *
    * This will destroy all AXComponent's attached to this AXEntity including the default AXTransform and AXRenderer
    */ 
    ~AXEntity();

    /*!
    * A method that calls start() on all the Components attached to this AXEntity
    *
    * This method is called by the AXScene at the start of the game loop 
    */ 
    void start();
    /*!
    * A method that calls update() on all the Components attached to this AXEntity
    *
    * This method is called by the AXScene every frame of the game loop 
    */ 
    void update();
    /*!
    * A method that calls draw on the AXRenderer attached to this AXEntity
    *
    * This method is called by the AXScene every frame of the game loop 
    *
    * What the AXRenderer will draw is defined by the draw type and if there are any Sprites attached
    * @param renderOffset passed by the AXScene to tell if AXRenderer if there's any offset applied to the drawing positions
    */ 
    void draw(const AXVector2D& renderOffset);

    /*!
    * A method that sets a flag for this AXEntity to be destroyed
    *
    * At the end of the frame that this method is called, the AXScene will destroy this AXEntity 
    */ 
    void destroy();
    /*!
    * A method that sets a flag how this AXEntity should be drawn
    *
    * @param type can be AX_DRAW_RECT/AX_DRAW_ELLIPSE/AX_DRAW_TEXT/AX_DRAW_SPRITE/AX_DRAW_NONE
    * @see AXEntityDrawTypes.hpp
    */ 
    void setDrawType(int type);

    /*!
    * A method that gets the flag how this AXEntity is being drawn
    *
    * @return The current draw type of this AXEntity
    * 
    * DrawTypes are: AX_DRAW_RECT/AX_DRAW_ELLIPSE/AX_DRAW_TEXT/AX_DRAW_SPRITE/AX_DRAW_NONE
    */ 
    int getDrawType();
    /*!
    * A method that moves the AXEntity by a set amount
    *
    * This method also moves any Colliders attached
    * @param v the vector of movement that should be summed to the current position
    */ 
    void moveEntity(AXVector2D v);
    /*!
    * A method that moves the AXEntity by a set amount
    *
    * This method also moves any Colliders attached
    * @param x the x value of movement that should be summed to the current position
    * @param y the y value of movement that should be summed to the current position
    */ 
    void moveEntity(float x, float y);
    /*!
    * A method that resizes the AXEntity by a set amount
    *
    * This method also resizes any Colliders attached
    * @param w the width value that the size will be set to
    * @param h the height value that the size will be set to
    */ 
    void resizeEntity(float w, float h);

    /*!
    * A method that sets the AXColour that this AXEntity should be drawn at
    *
    * This doesn't take affect if there's a AXSprite being drawn
    *
    * This method is calling another in the AXRenderer
    *
    * These values will be passed into a AXColour object so will be clamped from 0-255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    * @param a the alpha value
    */ 
    void setColour(float r, float g, float b, float a);
    /*!
    * A method that sets the AXColour that this AXEntity should be drawn at
    *
    * This doesn't take affect if there's a AXSprite being drawn
    *
    * This method is calling another in the AXRenderer
    *
    * These values will be passed into a AXColour object so will be clamped from 0-255
    *
    * This method assumes the alpha value is 255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    */ 
    void setColour(float r, float g, float b);
    /*!
    * A method that sets the AXColour that this AXEntity should be drawn at
    *
    * This doesn't take affect if there's a AXSprite being drawn
    *
    * This method is calling another in the AXRenderer
    * @param c the AXColour object this will draw at 
    */ 
    void setColour(const AXColour &c);
    /*!
    * A method that gets the AXColour that this AXEntity is being drawn at
    *
    * This method is calling another in the AXRenderer
    * @return the AXColour object this AXEntity is being drawn at
    */ 
    AXColour& getColour();
    /*!
    * A method to set the AXScene that this AXEntity is in
    *
    * This method doesn't inform the AXScene, it's called when you add an AXEntity to a AXScene using AXScene::addEntity()
    * @param s the AXScene this AXEntity is being attached to
    */ 
    void setScene(AXScene* s);
    /*!
    * A method to get the AXScene that this AXEntity is in
    *
    * @return the AXScene this AXEntity is attached to
    */ 
    AXScene* getScene();
    /*!
    * A method to set if this AXEntity is active or not
    *
    * If an AXEntity isn't active it won't be drawn, updated or collidable
    * @param value if the AXEntity is active or not
    */ 
    void setActive(bool value);
    /*!
    * A method to get if this AXEntity is active or not
    *
    * If an AXEntity isn't active it won't be drawn, updated or collidable
    * @return if the AXEntity is active or not
    */ 
    bool isActive();
    /*!
    * A method to set if this AXEntity is marked to be destroyed or not
    *
    * This is set by the AXEntity::destroy()
    * @return if the AXEntity is going to be destroyed at the end of this frame
    */     
    bool isDead();
    /*!
    * A method to get if this AXEntity is grounded
    *
    * An AXEntity is grounded if the attached AXCollider has reported a bottom collision in the last frame
    *
    * Will return false if there's no AXCollider attached
    * @return if this AXEntity is grounded
    */ 
    bool isGrounded();
    /*!
    * A method to add a AXRigidBody to this AXEntity
    *
    * This method will set the owner in the AXRigidBody
    * @param rb the AXRigidBody to attach
    */     
    void addRigidBody(AXRigidBody* rb);
    /*!
    * A method to add a AXRigidBody to this AXEntity
    *
    * This method will create a AXRigidBody for you
    *
    * This method will set the owner in the AXRigidBody
    * @param gravity the created AXRigidBody's gravity value
    */
    void addRigidBody(bool gravity);
    /*!
    * A method to get the AXRigidBody attached to this AXEntity
    *
    * This method will return nullptr if there's not a AXRigidBody present
    * @return the attached AXRigidBody
    */
    AXRigidBody* getRigidBody();
    /*!
    * A method that calls onCollision on all Components attached to this Enitity
    *
    * This is called by the AXScene when a collision occurs with another AXEntity, it will only collide if the layers are correct
    *
    * Catch this call inside of a AXComponent
    * @param e the AXEntity that collided with this one
    * @param direction the direction of which the collision happened
    */
    void onCollision(AXEntity* e, int direction);
    /*!
    * A method that calls onWorldCollision on all Components attached to this Enitity
    *
    * This is called by the AXScene when a collision occurs with the AXWorld or screen
    *
    * Catch this call inside of a AXComponent
    * @param direction the direction of which the collision happened
    */
    void onWorldCollision(int direction);
    /*!
    * A method that calls onClick on all Components attached to this Enitity
    *
    * This is called by the AXCollider when the it's clicked on
    *
    * Catch this call inside of a AXComponent
    * @param mouseButton the mouse button that was pressed
    */
    void onClick(int mouseButton);
    /*!
    * A method that calls onDestroy on all Components attached to this Enitity
    *
    * This is called by the AXScene just before the AXCollider is destroyed
    * 
    * Catch this call inside of a AXComponent
    */
    void onDestroy();
    /*!
    * A method that calls onHover on all Components attached to this Enitity
    *
    * This is called by the AXCollider when the mouse is over the AXEntity
    * Catch this call inside of a AXComponent
    */
    void onHover();
    /*!
    * A method that adds a AXCollider to this AXEntity
    *
    * This method will set the owner in the AXCollider
    * @param coll the AXCollider to be attached
    */
    void addCollider(AXCollider* coll);

    /*!
    * A method that gets the AXCollider on this AXEntity
    *
    * @return the AXCollider that's attached
    */
    AXCollider* getCollider();
    /*!
    * A method that attaches a AXComponent to this AXEntity
    *
    * The Components will be updated and called in the order that they're added
    * @param comp the AXComponent to be attached
    */
    void addComponent(AXComponent* comp);
    /*!
    * A method that gets the AXTransform attached to this AXEntity
    *
    * @return the AXTransform attache do this AXEntity
    */
    AXTransform* getTransform();
    /*!
    * A method that gets the AXRenderer attached to this AXEntity
    *
    * @return the AXRenderer attached do this AXEntity
    */
    AXRenderer* getRenderer();
    /*!
    * A method that gets the AXAudioPlayer attached to this AXEntity
    *
    * @return the AXAudioPlayer attached do this AXEntity
    */
    AXAudioPlayer* getAudioPlayer();
    /*!
    * A method that gets the name of this AXEntity
    *
    * @return the name of this AXEntity
    */
    std::string& getName();
    /*!
    * A method that gets the AXScene layer of this AXEntity
    *
    * @return the layer this AXEntity is in
    */
    int getLayer();
    /*!
    * A method that sets the AXScene layer of this AXEntity
    *
    * This method doesn't change the layer, it's when a AXEntity is added to an AXScene
    * @param layer the layer to set this AXEntity in
    */
    void setLayer(int layer);
    /*!
    * A method that sets the AXScene collision of this AXEntity
    *
    * @param layer the layer which this AXEntity will collide on, 0-17 or -1 for all
    */
    void setCollisionLayer(int layer);
    /*!
    * A method that gets the AXScene collision of this AXEntity
    *
    * @return the layer which this AXEntity will collide on, 0-17 or -1 for all
    */
    int getCollisionLayer();
    /*!
    * A method that sets the name of this AXEntity
    *
    * @param name the name to set
    */
    void setName(const std::string& name);
    /*!
    * A method that returns a clone of this AXEntity
    *
    * This will call clone on all Components attached
    * @return a clone of this AXEntity
    */
    AXEntity* clone();

    /*!
    * A method to get a typed AXComponent that's attached to this AXEntity
    *
    * This can be slow, store the result if using every frame
    * @return either nullptr or the found AXComponent of the given Type
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
