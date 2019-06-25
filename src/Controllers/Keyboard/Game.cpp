#include "Game.hpp"

GameKeyboardController::GameKeyboardController(KeyboardConfig* config) :
	config(config) {
	
}

void GameKeyboardController::apply(GameControls& game) {
	if (this->isKeyPressed(this->config->restart()))
		game.restart();
}

bool GameKeyboardController::isKeyPressed(const sf::Keyboard::Key& key) {
	return sf::Keyboard::isKeyPressed(key);
}
