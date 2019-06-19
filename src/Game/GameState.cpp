#include "GameState.hpp"

#define FIRST_LEVEL 1

GameState::GameState(Player* player, LevelManager* levelManager) :
	player(player),
	levelManager(levelManager) {
	
}

void GameState::restart() {
	if (this->player->isDead())
		this->levelManager->loadLevel(FIRST_LEVEL);
}

