#include "headers/AXAudioPlayer.hpp"

bool AXAudioPlayer::addAudioChunk(int chunkID, const std::string name){
	AXAudioChunk* temp = resourceManager->getAudioChunk(chunkID);
	if(temp){
		auto response = chunks.insert(std::pair<std::string, AXAudioChunk*>(name, temp));
		return response.second;
	}
	return false;
}

void AXAudioPlayer::playAudioChunk(const std::string& name){
	this->playAudioChunk(name, -1, 0);
}

void AXAudioPlayer::playAudioChunk(const std::string& name, int channel, int times){
	auto temp = chunks.find(name);
	if(temp != chunks.end()){
		AXAudio::playAudioChunk(temp->second, channel, times);
	}else{
		std::cout << "No AXAudioChunk with the name: " << name << std::endl;
	}
}

AXAudioPlayer* AXAudioPlayer::clone(){
	AXAudioPlayer* a = new AXAudioPlayer();
    for(auto it = chunks.begin(); it != chunks.end(); it++){
        //for each chunk, add it into the new player
        a->addAudioChunk(it->second->getID(), it->first);
    }
    return a;
}
