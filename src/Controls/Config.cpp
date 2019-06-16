#include "Config.hpp"

Config::Config(sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key jumpKey, sf::Keyboard::Key restartKey) :
	rightKey(rightKey),
	leftKey(leftKey),
	jumpKey(jumpKey),
	restartKey(restartKey) {
	
}

void Config::merge(Config &config) {
	this->setKey(config.right(), &this->rightKey);
	this->setKey(config.left(), &this->leftKey);
	this->setKey(config.jump(), &this->jumpKey);
	this->setKey(config.restart(), &this->restartKey);
}

sf::Keyboard::Key Config::right() {
	return this->rightKey;
}

sf::Keyboard::Key Config::left() {
	return this->leftKey;
}

sf::Keyboard::Key Config::jump() {
	return this->jumpKey;
}

sf::Keyboard::Key Config::restart() {
	return this->restartKey;
}

void Config::setKey(sf::Keyboard::Key value, sf::Keyboard::Key* destination) {
	if (value != sf::Keyboard::Key::Unknown)
		if (!this->isAlreadyAssigned(value))
			*destination = value;
}

bool Config::isAlreadyAssigned(sf::Keyboard::Key& value) {
	return value == this->rightKey ||
		value == this->leftKey ||
		value == this->jumpKey ||
		value == this->restartKey;
}
