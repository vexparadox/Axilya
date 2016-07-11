#include "Destroyable.hpp"

void Destroyable::onClick(int mousebutton){
    owner->getComponent<exampleComponent>()->x = 123; // an example of getting another component on this entity
    
    owner->destroy();
}