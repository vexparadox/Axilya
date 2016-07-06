#ifndef exampleComponent_hpp
#define exampleComponent_hpp

#include <CoreMain.h>
class exampleComponent : public Component{
    public:
    int x = 5;
    exampleComponent(Entity* owner);
    virtual void update();
};
#endif