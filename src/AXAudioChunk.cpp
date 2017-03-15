#include "headers/AXAudioChunk.hpp"
#include "headers/AXWindow.hpp"

AXAudioChunk::AXAudioChunk(int id, const std::string& path) : AXResource(id){
	loadAudio(path);
}

AXAudioChunk::AXAudioChunk(const std::string& path) : AXResource(-1){
	loadAudio(path);
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
		std::cout << "Audio chunk failed to load: " << Mix_GetError() << std::endl;
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