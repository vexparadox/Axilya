#include "headers/AXAudio.hpp"
#include "headers/AXWindow.hpp"
namespace AXAudio{
	void playAudioChunk(const std::unique_ptr<AXAudioChunk>& chunk, int channel, int loopNumber){
		playAudioChunk(chunk.get(), channel, loopNumber);
	}

	void playAudioChunk(const std::unique_ptr<AXAudioChunk>& chunk, int channel){
		playAudioChunk(chunk.get(), channel);
	}

	void playAudioChunk(const std::unique_ptr<AXAudioChunk>& chunk){
		playAudioChunk(chunk.get());
	}

	void playAudioChunk(const AXAudioChunk* chunk, int channel, int loopNumber){
		//only play if audio is inited
		if(AXWindow::audioStatus){
			if(Mix_PlayChannel(channel, chunk->getAudioData(), loopNumber) == -1){
				AXLog::log("AudioChunk failed to play", Mix_GetError(), AX_LOG_ERROR);
			}
		}
	}
	void playAudioChunk(AXAudioChunk* chunk, int loopNumber){
		playAudioChunk(chunk, -1, loopNumber);
	}
	void playAudioChunk(AXAudioChunk* chunk){
		playAudioChunk(chunk, -1, 0);
	}
};
