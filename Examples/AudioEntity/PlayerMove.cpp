#include "PlayerMove.hpp"

void PlayerMove::onWorldCollision(int direction){
	//if it hits the bottom of the screen, play a sound
	//only play if this is a new collision however
	if(direction == AX_COLLIDE_DOWN && lastCollision != AX_COLLIDE_DOWN){
		owner->getAudioPlayer()->playAudioChunk("playerAudio");
	}
	//store the collision
	lastCollision = direction;
}