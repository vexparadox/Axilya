#ifndef PlayerController_hpp
#define PlayerController_hpp
#include <Axilya/AXMain.h>
class Bullet;
class PlayerController : public AXCustomComponent<PlayerController>{
	Bullet* bullet;
	AXText* text;
	int score = 0;
public:
	void start();
	void update();
	void bulletDead(bool hitEnemy);
};
#endif