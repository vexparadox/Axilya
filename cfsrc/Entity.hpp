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
// #include "Transform.hpp"
// #include "RigidBody.hpp"
#include "Components.h"

#endif /* Entity_hpp */

class Entity{
    //a list of components
    Transform* transform;
    std::vector<Component*> components;
    Collider* collider;
    Graphics::Image* texture;
public:
    //constructors
    Entity(const Math::Vector2D& pos);
    virtual void update();
    virtual void draw();
    //add a new texture
    void addTexture(std::string);
    void addTexture(Graphics::Image*);
    //get the texture
    Graphics::Image* getTexture();
    //add a new component
    void addComponent(Component*);
    //return the transform
    Transform* getTransform();
};