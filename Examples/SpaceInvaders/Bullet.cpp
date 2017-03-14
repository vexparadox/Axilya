#include "Bullet.hpp"

void Bullet::update(){
	owner->moveEntity(0, -5);
}

void Bullet::onCollision(AXEntity* e){
	e->destroy();
	owner->destroy();
}

void Bullet::onWorldCollision(int direction){
	owner->destroy();
}

void Bullet::onDestroy(){
	pc->bulletDead();
}