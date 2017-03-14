#ifndef PlayerMove_hpp
#define PlayerMove_hpp
#include <Axilya/AXMain.h>

class PlayerMove : public CustomComponent<PlayerMove>{
	AXRigidBody* rb;
public:
	void start();
	void update();
};

#endif
