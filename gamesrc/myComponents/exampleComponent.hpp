#ifndef exampleComponent_hpp
#define exampleComponent_hpp

#include <CoreMain.h>
class exampleComponent : public Component{
    public:
    int x = 5;
    exampleComponent();
    virtual void update();
    virtual void onClick(int mouseButton);
    virtual void onHover();
};
#endif