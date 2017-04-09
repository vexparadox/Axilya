#include "GameMaster.hpp"

void GameMaster::addScore(int player, int score){
	if(player == 1){
		player1score += score;
		AXLog::log("player1 scored", std::to_string(score), AX_LOG_DEBUG);
		AXLog::log("player1 total", std::to_string(player1score), AX_LOG_DEBUG);
	}else{
		player2score += score;
		AXLog::log("player2 scored", std::to_string(score), AX_LOG_DEBUG);
		AXLog::log("player2 total", std::to_string(player2score), AX_LOG_DEBUG);
	}
}