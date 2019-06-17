#include "Config.hpp"

Config::Config(sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key jumpKey, sf::Keyboard::Key restartKey) :
	keyMap {
		{KeyType::rightKey, rightKey},
		{KeyType::leftKey, leftKey},
		{KeyType::jumpKey, jumpKey},
		{KeyType::restartKey, restartKey},
	} {
	
}

void Config::merge(Config &config) {
	this->bindKey(config.right(), KeyType::rightKey);
	this->bindKey(config.left(), KeyType::leftKey);
	this->bindKey(config.jump(), KeyType::jumpKey);
	this->bindKey(config.restart(), KeyType::restartKey);
}

sf::Keyboard::Key Config::right() {
	return this->getKey(KeyType::rightKey);
}

sf::Keyboard::Key Config::left() {
	return this->getKey(KeyType::leftKey);
}

sf::Keyboard::Key Config::jump() {
	return this->getKey(KeyType::jumpKey);
}

sf::Keyboard::Key Config::restart() {
	return this->getKey(KeyType::restartKey);
}

void Config::bindKey(sf::Keyboard::Key value, const KeyType& destination) {
	if (value != sf::Keyboard::Key::Unknown) {
		this->unbindSameKeys(value);
		this->setKey(value, destination);
	}
}

void Config::unbindSameKeys(sf::Keyboard::Key& value) {
	for (auto& pair : this->keyMap)
		if (value == pair.second)
			this->unbindKey(pair.first);
}

void Config::unbindKey(const KeyType& destination) {
	this->setKey(sf::Keyboard::Key::Unknown, destination);
}

sf::Keyboard::Key Config::getKey(const KeyType& destination) {
	return this->keyMap[destination];
}

void Config::setKey(sf::Keyboard::Key value, const KeyType& destination) {
	this->keyMap[destination] = value;
}
