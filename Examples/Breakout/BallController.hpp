#ifndef BallController_hpp
#define BallController_hpp
#include <Axilya/AXMain.h>

class BallController : public CustomComponent<BallController>{
	Math::Vector2D velocity;
	bool hasStarted;
public:
	void start();
	void update();
	void onCollision(Entity* e);
	void onWorldCollision(int direction);
};
#endif