#include "GameMaster.hpp"

void GameMaster::addScore(int player, int score){
	if(player == 1){
		player1score += score;
		std::cout << "player1 scored: " << score << std::endl;
		std::cout << "player1 total: " << player1score << std::endl;
	}else{
		player2score += score;
		std::cout << "player2 scored: " << score << std::endl;
		std::cout << "player2 total: " << player2score << std::endl;
	}
}