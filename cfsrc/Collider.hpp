#ifndef Collider_hpp
#define Collider_hpp

#include "Component.hpp"
#include <stdio.h>

class Collider : public Component{
public:
    Collider(Entity* owner);
};

#endif