#ifndef BallController_hpp
#define BallController_hpp
#include <Axilya/AXMain.h>

class BallController : public AXCustomComponent<BallController>{
	AXVector2D velocity;
	bool hasStarted;
public:
	void start();
	void update();
	void onCollision(AXEntity* e);
	void onWorldCollision(int direction);
};
#endif