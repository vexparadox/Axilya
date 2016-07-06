//
//  Transform.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "Component.hpp"
class Entity;
class Transform : public Component{
    Math::Vector2D position, size, lastPosition;
public:
    /*!
    * Constructor of the Transform
    * This is called automatically by the Entity constructor
    * @param pos the Entities position
    * @param size the Entities size
    * @param owner The Entity this Component belongs too
    * @see Entity constructor
    */
    Transform(const Math::Vector2D& pos, const Math::Vector2D& size);
    Transform(float x, float y, float w, float h);
    /*!
    * Sets the transforms parameters
    */
    void set(const Math::Vector2D &v, const Math::Vector2D &s);
    /*!
    * Sets the transforms position only
    */
    void set(const Math::Vector2D &v);
    /*!
    * Sets the transforms position only
    */
    void set(float x, float y);
    /*!
    * Moves the transform
    */
    void moveTransform(const Math::Vector2D &v);
    /*!
    * Returns the position
    * @return the position of the Entity
    */
    Math::Vector2D& getPos();
    /*!
    * Returns the size
    * @return the size of the Entity
    */
    Math::Vector2D& getSize();
};
#endif /* Transform_hpp */
