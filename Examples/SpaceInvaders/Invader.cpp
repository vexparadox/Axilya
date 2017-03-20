#include "Invader.hpp"

void Invader::onCollision(AXEntity* e){
	owner->getAudioPlayer()->playAudioChunk("death");
}