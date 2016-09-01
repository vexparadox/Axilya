#ifndef Destroyable_hpp
#define Destroyable_hpp

#include "gamesrc/CoreMain.h"
class Destroyable : public Component{
    public:
    int x = 0;
    virtual void onClick(int mouseButton);
};
#endif