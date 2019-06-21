#include "Factory.hpp"

KeyboardControllerFactory::KeyboardControllerFactory(Config* config) :
	config(config) {
	
}

PlayerController* KeyboardControllerFactory::makePlayerController() {
	return new PlayerKeyboardController(this->config);
}

GameController* KeyboardControllerFactory::makeGameController() {
	return new GameKeyboardController(this->config);
}
