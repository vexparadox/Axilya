#ifndef exampleComponent_hpp
#define exampleComponent_hpp

#include <CoreMain.h>
class exampleComponent : public Component{
    public:
    exampleComponent(Entity* owner);
    virtual void update();
};
#endif