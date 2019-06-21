#include "GameLoop.hpp"

GameLoop::GameLoop(Player* player, CurrentLevel* level) :
	player(player),
	level(level) {
	
}

void GameLoop::handleInputs() {
	
}

void GameLoop::update(const float& deltaTime) {
	this->applyGravity();
	this->updateX(deltaTime);
	// check for collisions in X axis
	this->updateY(deltaTime);
	// check for collisions in Y axis
	// handle hazzards
}

void GameLoop::applyGravity() {
	
}

void GameLoop::updateX(const float& deltaTime) {
	
}

void GameLoop::updateY(const float& deltaTime) {
	
}
