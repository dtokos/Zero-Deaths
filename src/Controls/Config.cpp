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
	this->bindKey(KeyType::rightKey, config.right());
	this->bindKey(KeyType::leftKey, config.left());
	this->bindKey(KeyType::jumpKey, config.jump());
	this->bindKey(KeyType::restartKey, config.restart());
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

void Config::bindKey(const KeyType& key, sf::Keyboard::Key value) {
	if (value != sf::Keyboard::Key::Unknown) {
		this->unbindSameKeys(value);
		this->setKey(key, value);
	}
}

void Config::unbindSameKeys(sf::Keyboard::Key& value) {
	for (auto& pair : this->keyMap)
		if (value == pair.second)
			this->unbindKey(pair.first);
}

void Config::unbindKey(const KeyType& key) {
	this->setKey(key, sf::Keyboard::Key::Unknown);
}

sf::Keyboard::Key Config::getKey(const KeyType& key) {
	return this->keyMap[key];
}

void Config::setKey(const KeyType& key, sf::Keyboard::Key value) {
	this->keyMap[key] = value;
}
