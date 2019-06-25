#include "Player.hpp"

PlayerKeyboardController::PlayerKeyboardController(KeyboardConfig* config) :
	config(config) {
	
}

void PlayerKeyboardController::apply(PlayerControls& player) {
	if (this->isKeyPressed(this->config->jump()))
		player.jump();
	
	player.move(this->getMoveType());
}

bool PlayerKeyboardController::isKeyPressed(const sf::Keyboard::Key& key) {
	return sf::Keyboard::isKeyPressed(key);
}

PlayerMoveType PlayerKeyboardController::getMoveType() {
	unsigned char moveType = this->calculateMoveType();
	
	return this->convertMoveType(moveType);
}

char PlayerKeyboardController::calculateMoveType() {
	return (
		0 +
		this->isKeyPressed(this->config->right()) -
		this->isKeyPressed(this->config->left())
	);
}

PlayerMoveType PlayerKeyboardController::convertMoveType(char moveType) {
	switch (moveType) {
		case -1:
			return PlayerMoveType::left;
		
		case 0:
			return PlayerMoveType::none;
			
		case 1:
			return PlayerMoveType::right;
	}
}
