#include "headers/AXAudioChunk.hpp"
#include "headers/AXWindow.hpp"
#include <cstring>

AXAudioChunk::AXAudioChunk(int id, const std::string& path) : AXResource(id){
	loadAudio(path);
}

AXAudioChunk::AXAudioChunk(const std::string& path) : AXResource(-1){
	loadAudio(path);
}

AXAudioChunk::~AXAudioChunk(){
	Mix_FreeChunk(chunk);
}

bool AXAudioChunk::loadAudio(const std::string& path){
	std::string temp = AXWindow::runPath+ "data/" + path;
	if(loaded){
		Mix_FreeChunk(chunk);
		chunk = 0;
	}
	loaded = false;
	chunk = Mix_LoadWAV(temp.c_str());
	if(!chunk){
		AXLog::log("Audio chunk failed to load.", Mix_GetError(), AX_LOG_ERROR);
		loaded = false;
		return false;
	}
	loaded = true;
	return true;
}

int AXAudioChunk::setVolume(int volume){
	if(loaded){
		return Mix_VolumeChunk(chunk, volume);
	}
	return -1;
}

Mix_Chunk* AXAudioChunk::getAudioData(){
	if(loaded){
		return chunk;
	}else{
		return 0;
	}
}

AXAudioChunk* AXAudioChunk::clone(){
	AXAudioChunk* temp = new AXAudioChunk();
	temp->setPath(path);
	if (loaded){
		temp->chunk = (Mix_Chunk*) std::malloc(sizeof(chunk));
		std::memcpy(temp->chunk, chunk, sizeof(chunk));
	}
	return temp;
}