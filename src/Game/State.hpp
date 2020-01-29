#ifndef GameState_hpp
#define GameState_hpp

#include "Controllers/Game.hpp"
#include "./Player/Player.hpp"
#include "./Level/Manager.hpp"

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
	void loadLevel(int levelNumber);
	void loadNextLevel();
	void spawnPlayer();
	
};

#endif
