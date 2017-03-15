#ifndef Invader_hpp
#define Invader_hpp

#include <Axilya/AXMain.h>

class Invader : public AXCustomComponent<Invader>{
public:
	void onCollision(AXEntity* e);
};
#endif