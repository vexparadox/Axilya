#ifndef PlayerMove_hpp
#define PlayerMove_hpp
#include <Axilya/AXMain.h>

class PlayerMove : public CustomComponent<PlayerMove>{
	RigidBody* rb;
public:
	void start();
	void update();
};

#endif
