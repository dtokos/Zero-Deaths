#include "State.hpp"

#define FIRST_LEVEL 1

GameState::GameState(Player* player, LevelManager* levelManager, GameController* controller) :
	player(player),
	levelManager(levelManager),
	controller(controller) {
		this->loadLevel(FIRST_LEVEL);
}

void GameState::handleInputs() {
	this->controller->apply(*this);
}

void GameState::restart() {
	if (this->player->isDead())
		this->loadLevel(FIRST_LEVEL);
}

void GameState::update() {
	if (this->isInFinish())
		this->loadNextLevel();
}

bool GameState::isInFinish() {
	
}

void GameState::loadLevel(int levelNumber) {
	this->levelManager->loadLevel(levelNumber);
	this->spawnPlayer();
}

void GameState::loadNextLevel() {
	this->levelManager->loadNextLevel();
	// respawn player
}

void GameState::spawnPlayer() {
	Level* level = this->levelManager->current();
	Tile* start = level->startTile();
	sf::Vector2f position = start->getPosition();
	
	this->player->setPosition(position);
	//sf::Vector2f asd(100, 500);
	//this->player->setPosition(asd);
}
