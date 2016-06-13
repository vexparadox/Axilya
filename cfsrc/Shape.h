#ifndef Shape_H
#define Shape_H
#include "Vector2D.h"
class Shape{
protected:
    Math::Vector2D position, size;
public:
    /*!
    * Constructor of Shapes
    * Rects, Ellipses (and Triangles) are Shapes
    * @param v the center position of the Shape
    */
    Shape(const Math::Vector2D& v, const Math::Vector2D& size){
        this->position = v;
        this->size = size;
    }

    virtual const float getWidth() const = 0;
    virtual const float getHeight() const = 0;
    virtual const Math::Vector2D& getPosition() const = 0;
    virtual const Math::Vector2D& getSize() const = 0; 
};
#endif