#include "Destroyable.hpp"

void Destroyable::onClick(int mousebutton){
    owner->destroy();
}