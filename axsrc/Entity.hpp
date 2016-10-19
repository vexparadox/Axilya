//
//  Entity.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>

#include "Math.h"
#include "ResourceManager.hpp"
#include "PrefabManager.hpp"
//components
#include "Components.h"
#include "Animator.hpp"
#include "EntityDrawTypes.hpp"
class Scene;
class Entity{
    //get an instance of the resourcemanager
    ResourceManager* resourceManager = ResourceManager::getInstance();
    PrefabManager* prefabManager = PrefabManager::getInstance();
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
    //a list of custom components
    std::vector<Component*> components;
    //Animator holds all of the drawing capabilities of the Entitity
    Animator* animator = 0;
    void handle_eptr(std::exception_ptr);
    //default to drawing rect
    EntityDrawType drawType = EntityDrawType::RECT;
public:
    //constructors
    Entity(const std::string& name, const Math::Vector2D& pos, const Math::Vector2D& size);
    Entity(const std::string& name, float x, float y, float w, float h);
    virtual ~Entity();
    //update and draws
    virtual void update();
    virtual void draw();

    //this method deletes all the data to do with this entity
    void destroy();
    
    void setDrawType(EntityDrawType type);
    EntityDrawType getDrawType();
    //moves the transform and any colliders attached by a certain amount
    void moveEntity(Math::Vector2D v);
    //set and get the colour
    void setColour(float r, float g, float b, float a);
    void setColour(float r, float g, float b);
    void setColour(const Graphics::Colour &c);
    const Graphics::Colour& getColour();
    //set and get scene
    void setScene(Scene*);
    Scene* getScene();
    //get and set the active state of the entity
    void setActive(bool a);
    bool isActive();
    //check if the enitity should die
    bool isDead();
    //add RigidBody
    void addRigidBody(RigidBody*);
    void addRigidBody(bool);
    //get the rigidBody
    RigidBody* getRigidBody();
    //when a collision happens
    void onCollision(Entity* e);

    void onWorldCollision();
    //when a click happens
    void onClick(int mouseButton);
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
    Animator* getAnimator();
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