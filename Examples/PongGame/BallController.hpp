#ifndef BallController_hpp
#define BallController_hpp value

#include <Axilya/AXMain.h>
#include <stdlib.h>
#include <time.h>
class BallController : public AXCustomComponent<BallController>{
	AXVector2D velocity;
	bool hasStarted;
public:
	void start();
	void onCollision(AXEntity* e);
	void onWorldCollision(int direction);
	void update();
};

#endif