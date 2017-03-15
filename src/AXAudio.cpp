#include "headers/AXAudio.hpp"
namespace AXAudio{
	void playAudioChunk(AXAudioChunk* chunk, int channel, int loopNumber){
		if(Mix_PlayChannel(channel, chunk->getAudioData(), loopNumber) == -1){
			std::cout << "AudioChunk failed to play: " << Mix_GetError() << std::endl;
		}
	}
	void playAudioChunk(AXAudioChunk* chunk, int loopNumber){
		playAudioChunk(chunk, -1, loopNumber);
	}
	void playAudioChunk(AXAudioChunk* chunk){
		playAudioChunk(chunk, -1, 0);
	}
};