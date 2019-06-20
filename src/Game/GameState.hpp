#ifndef GameState_hpp
#define GameState_hpp

#include "../Player/Player.hpp"
#include "../Level/Level.hpp"
#include "../Level/LevelManager.hpp"

class GameState {
	
public:
	GameState(Player* player, LevelManager* levelManager);
	void restart();
	void update();
	
private:
	Player* player;
	LevelManager* levelManager;
	
	bool isInFinish();
	
};

#endif
