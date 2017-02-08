#ifndef Invader_hpp
#define Invader_hpp

#include <Axilya/AXMain.h>

class Invader : public CustomComponent<Invader>{
public:
	void onCollision(Entity* e);
};
#endif