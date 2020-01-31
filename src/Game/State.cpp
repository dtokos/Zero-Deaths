#include "State.hpp"

#define FIRST_LEVEL 1

GameState::GameState(Player* player, LevelManager* levelManager, GameController* controller, StatusBar* statusBar) :
	player(player),
	levelManager(levelManager),
	controller(controller),
	statusBar(statusBar) {
		this->loadLevel(21);
}

void GameState::handleInputs() {
	this->controller->apply(*this);
}

void GameState::restart() {
	if (this->player->isDead()) {
		this->loadLevel(FIRST_LEVEL);
		this->statusBar->incrementRestarts();
	}
}

void GameState::update() {
	if (this->isInFinish() && !this->levelManager->didFinishAllLevels())
		this->loadNextLevel();
}

bool GameState::isInFinish() {
	sf::FloatRect playerBody = this->player->getColisionBody();
	sf::FloatRect finishBody = this->levelManager->current()->finishTile()->getCollisionBody();
	
	return finishBody.contains(playerBody.left + playerBody.width / 2, playerBody.top + playerBody.height / 2);
}

void GameState::loadLevel(int levelNumber) {
	this->levelManager->loadLevel(levelNumber);
	this->spawnPlayer();
	this->statusBar->setLevel(levelNumber);
}

void GameState::loadNextLevel() {
	this->levelManager->loadNextLevel();
	this->spawnPlayer();
	this->statusBar->setLevel(this->levelManager->currentNumber());
	
	if (this->levelManager->didFinishAllLevels())
		this->statusBar->stopStopwatch();
}

void GameState::spawnPlayer() {
	Level* level = this->levelManager->current();
	Tile* start = level->startTile();
	sf::Vector2f position = start->getPosition();
	
	this->player->setPosition(position);
	this->player->setVelocityY(0);
	this->player->respawn();
}
