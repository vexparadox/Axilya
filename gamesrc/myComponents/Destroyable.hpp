#ifndef Destroyable_hpp
#define Destroyable_hpp

#include <CoreMain.h>
class Destroyable : public Component{
    public:
    virtual void onClick(int mouseButton);
};
#endif