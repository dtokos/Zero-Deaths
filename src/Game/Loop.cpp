#include "Loop.hpp"

#define GRAVITY 50.0f

GameLoop::GameLoop(Player* player, CurrentLevel* level, PlayerController* playerController) :
	player(player),
	level(level),
	playerController(playerController) {
	
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
}

void GameLoop::updateX(const float& deltaTime) {
	this->player->updateX(deltaTime);
}

void GameLoop::updateY(const float& deltaTime) {
	this->player->updateY(deltaTime, GRAVITY);
}

void GameLoop::collideX() {
	
}

void GameLoop::collideY() {
	sf::FloatRect playerBody = this->player->getColisionBody();
	
	this->level->current()->tileAt(sf::Vector2f(playerBody.left, playerBody.top))->collideY(*this->player);
	this->level->current()->tileAt(sf::Vector2f(playerBody.left + playerBody.width, playerBody.top))->collideY(*this->player);
	this->level->current()->tileAt(sf::Vector2f(playerBody.left, playerBody.top + playerBody.height))->collideY(*this->player);
	this->level->current()->tileAt(sf::Vector2f(playerBody.left + playerBody.width, playerBody.top + playerBody.height))->collideY(*this->player);
}
