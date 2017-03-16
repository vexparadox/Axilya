#ifndef PlayerMove_hpp
#define PlayerMove_hpp
#include <Axilya/AXMain.h>

class PlayerMove : public AXCustomComponent<PlayerMove>{
	int lastCollision = -1;
public:
	void onWorldCollision(int direction);
};
#endif