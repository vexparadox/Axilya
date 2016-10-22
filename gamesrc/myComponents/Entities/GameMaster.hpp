#ifndef GameMaster_hpp
#define GameMaster_hpp
#include <CoreMain.h>
class GameMaster : public CustomComponent<GameMaster>{
	int score = 0;
public:
	void gameOver();
	void increaseScore();
	int getScore();
};
#endif