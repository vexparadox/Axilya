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
#include "Graphics.hpp"
//components
#include "Components.h"

#endif /* Entity_hpp */

class Entity{
    //a list of standard components
    Transform* transform = 0;
    Collider* collider = 0;
    RigidBody* rigidBody = 0;
    //a list of custom components
    std::vector<Component*> components;
    Graphics::Image* texture = 0;
public:
    //constructors
    Entity(const Math::Vector2D& pos, const Math::Vector2D& size);
    Entity(float x, float y, float w, float h);
    virtual void update();
    virtual void draw();
    //add a new texture
    void addTexture(std::string);
    void addTexture(Graphics::Image*);
    //add RigidBody
    void addRigidBody(RigidBody*);
    void addRigidBody(bool);
    //get the texture
    Graphics::Image* getTexture();
    //add a collider
    void addCollider(Collider*);
    //get the collider
    Collider* getCollider();
    //add a new component
    void addComponent(Component*);
    //return the transform
    Transform* getTransform();
};