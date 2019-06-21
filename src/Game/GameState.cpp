#include "GameState.hpp"

#define FIRST_LEVEL 1

GameState::GameState(Player* player, LevelManager* levelManager, GameController* controller) :
	player(player),
	levelManager(levelManager),
	controller(controller) {
	
}

void GameState::handleInputs() {
	this->controller->apply(*this);
}

void GameState::restart() {
	if (this->player->isDead())
		this->levelManager->loadLevel(FIRST_LEVEL);
}

void GameState::update() {
	if (this->isInFinish())
		this->levelManager->nextLevel();
}

bool GameState::isInFinish() {
	
}
