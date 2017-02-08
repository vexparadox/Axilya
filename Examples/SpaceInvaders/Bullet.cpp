#include "Bullet.hpp"

void Bullet::update(){
	owner->moveEntity(0, -5);
}

void Bullet::onCollision(Entity* e){
	pc->bulletDead();
	e->destroy();
	owner->destroy();
}

void Bullet::onWorldCollision(){
	pc->bulletDead();
	owner->destroy();
}