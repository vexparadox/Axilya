#include "GameMaster.hpp"

void GameMaster::gameOver(){
	//safley shut down the program
	Runner::shutdown();
}

void GameMaster::increaseScore(){
	this->score++;
}

int GameMaster::getScore(){
	return this->score;
}