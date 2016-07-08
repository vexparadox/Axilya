#include "Destroyable.hpp"

Destroyable::Destroyable(){

}

void Destroyable::onClick(int mousebutton){
    owner->destroy();
}