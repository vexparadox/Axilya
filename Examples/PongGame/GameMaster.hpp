#ifndef GameMaster_hpp
#define GameMaster_hpp

#include <Axilya/AXMain.h>

class GameMaster : public CustomComponent<GameMaster>{
	int player1score;
	int player2score;
public:
	void addScore(int player, int score);
};


#endif