#include "State.hpp"

#define FIRST_LEVEL 1

GameState::GameState(Player* player, LevelManager* levelManager, GameController* controller, StatusBar* statusBar) :
	player(player),
	levelManager(levelManager),
	controller(controller),
	statusBar(statusBar) {
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
	sf::FloatRect playerBody = this->player->getColisionBody();
	sf::FloatRect finishBody = this->levelManager->current()->finishTile()->getCollisionBody();
	
	return finishBody.contains(playerBody.left + playerBody.width / 2, playerBody.top + playerBody.height / 2);
}

void GameState::loadLevel(int levelNumber) {
	this->statusBar->setLevel(levelNumber);
	this->levelManager->loadLevel(levelNumber);
	this->spawnPlayer();
}

void GameState::loadNextLevel() {
	this->statusBar->setLevel(this->levelManager->currentNumber());
	this->levelManager->loadNextLevel();
	this->spawnPlayer();
}

void GameState::spawnPlayer() {
	Level* level = this->levelManager->current();
	Tile* start = level->startTile();
	sf::Vector2f position = start->getPosition();
	
	this->player->setPosition(position);
}
