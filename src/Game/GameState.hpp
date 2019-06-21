#ifndef GameState_hpp
#define GameState_hpp

#include "../Player/Player.hpp"
#include "../Level/Level.hpp"
#include "../Level/LevelManager.hpp"
#include "../Controls/GameController.hpp"
#include "GameControls.hpp"

class GameState : public virtual GameControls {
	
public:
	GameState(Player* player, LevelManager* levelManager, GameController* controller);
	void handleInputs();
	virtual void restart();
	void update();
	
private:
	Player* player;
	LevelManager* levelManager;
	GameController* controller;
	
	
	bool isInFinish();
	
};

#endif
