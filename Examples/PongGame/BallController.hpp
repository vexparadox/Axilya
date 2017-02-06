#ifndef BallController_hpp
#define BallController_hpp value

#include <Axilya/AXMain.h>

class BallController : public CustomComponent<BallController>{
	Math::Vector2D velocity;
public:
	void onCollision(Entity* e);
	void onWorldCollision(int direction);
	void start();
	void update();
};

#endif