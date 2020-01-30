#include "Loop.hpp"

#define GRAVITY 50.0f

GameLoop::GameLoop(Player* player, CurrentLevel* level, PlayerController* playerController, StatusBar *statusBar) :
	player(player),
	level(level),
	playerController(playerController),
	statusBar(statusBar) {
	
}

void GameLoop::handleInputs() {
	this->playerController->apply(*this->player);
}

void GameLoop::update(const float& deltaTime) {
	this->updateX(deltaTime);
	// check for collisions in X axis
	this->collideX();
	this->updateY(deltaTime);
	this->collideY();
	// check for collisions in Y axis
	// handle hazzards
	this->statusBar->update(deltaTime);
}

void GameLoop::updateX(const float& deltaTime) {
	this->player->updateX(deltaTime);
}

void GameLoop::updateY(const float& deltaTime) {
	this->player->updateY(deltaTime, GRAVITY);
}

void GameLoop::collideX() {
	sf::FloatRect playerBody = this->player->getColisionBody();
	Level *currentLevel = this->level->current();
	
	currentLevel->tileAt(sf::Vector2f(playerBody.left, playerBody.top))->collideX(*this->player);
	currentLevel->tileAt(sf::Vector2f(playerBody.left + playerBody.width, playerBody.top))->collideX(*this->player);
	currentLevel->tileAt(sf::Vector2f(playerBody.left, playerBody.top + playerBody.height))->collideX(*this->player);
	currentLevel->tileAt(sf::Vector2f(playerBody.left + playerBody.width, playerBody.top + playerBody.height))->collideX(*this->player);
}

void GameLoop::collideY() {
	sf::FloatRect playerBody = this->player->getColisionBody();
	Level *currentLevel = this->level->current();
	
	currentLevel->tileAt(sf::Vector2f(playerBody.left, playerBody.top))->collideY(*this->player);
	currentLevel->tileAt(sf::Vector2f(playerBody.left + playerBody.width, playerBody.top))->collideY(*this->player);
	currentLevel->tileAt(sf::Vector2f(playerBody.left, playerBody.top + playerBody.height))->collideY(*this->player);
	currentLevel->tileAt(sf::Vector2f(playerBody.left + playerBody.width, playerBody.top + playerBody.height))->collideY(*this->player);
}
