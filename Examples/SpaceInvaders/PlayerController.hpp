#ifndef PlayerController_hpp
#define PlayerController_hpp
#include <Axilya/AXMain.h>
class Bullet;
class PlayerController : public CustomComponent<PlayerController>{
	Bullet* bullet;
public:
	void update();
	void bulletDead();
};
#endif