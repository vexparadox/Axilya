#include "Bullet.hpp"

void Bullet::update(){
	owner->moveEntity(0, -5);
}

void Bullet::onCollision(AXEntity* e){
	e->destroy();
	owner->destroy();
	hasScored = true;
}

void Bullet::onWorldCollision(int direction){
	hasScored = false;
	owner->destroy();
}

void Bullet::onDestroy(){
	pc->bulletDead(hasScored);
}