//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>

AXAudioChunk* chunk;

void update(){
	if(AXInput::getValue("SPACE")){
		AXAudio::playAudioChunk(chunk);
	}
}

void draw(){

}

int main(int argc, char const *argv[]){	
	AXWindow::init(720, 480, "Audio Raw", AX_WINDOWED, update, draw);
	//create the audio chunk
	chunk = new AXAudioChunk("data/example.wav");
	return AXWindow::run();
}