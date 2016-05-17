#ifndef Collider_hpp
#define Collider_hpp

#include "Component.hpp"
class Collider : public Component{
public:
    Collider(Entity* owner);
};

#endif