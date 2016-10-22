#ifndef exampleComponent_hpp
#define exampleComponent_hpp

#include <CoreMain.h>
#include <GameMaster.hpp>
class RigidBodyMove : public CustomComponent<RigidBodyMove>{
	GameMaster* gm = 0;
    public:
    int x = 5;
    virtual void start();
    virtual void update();
    virtual void onHover();
    virtual void onCollision(Entity* e);
};
#endif