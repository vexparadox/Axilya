#ifndef Destroyable_hpp
#define Destroyable_hpp

#include <CoreMain.h>
class Destroyable : public CustomComponent<Destroyable>{
    public:
    int x = 0;
    virtual void onClick(int mouseButton);
};
#endif