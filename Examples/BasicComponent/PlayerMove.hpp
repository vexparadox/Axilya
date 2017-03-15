#ifndef PlayerMove_hpp
#define PlayerMove_hpp
#include <Axilya/AXMain.h>

class PlayerMove : public AXCustomComponent<PlayerMove>{
	AXRigidBody* rb;
public:
	void start();
	void update();
};

#endif
