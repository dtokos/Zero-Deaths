#include "Config.hpp"

KeyboardConfig::KeyboardConfig(sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key jumpKey, sf::Keyboard::Key restartKey) :
	keyMap {
		{KeyType::rightKey, rightKey},
		{KeyType::leftKey, leftKey},
		{KeyType::jumpKey, jumpKey},
		{KeyType::restartKey, restartKey},
	} {
	
}

void KeyboardConfig::merge(KeyboardConfig &config) {
	this->bindKey(KeyType::rightKey, config.right());
	this->bindKey(KeyType::leftKey, config.left());
	this->bindKey(KeyType::jumpKey, config.jump());
	this->bindKey(KeyType::restartKey, config.restart());
}

sf::Keyboard::Key KeyboardConfig::right() {
	return this->getKey(KeyType::rightKey);
}

sf::Keyboard::Key KeyboardConfig::left() {
	return this->getKey(KeyType::leftKey);
}

sf::Keyboard::Key KeyboardConfig::jump() {
	return this->getKey(KeyType::jumpKey);
}

sf::Keyboard::Key KeyboardConfig::restart() {
	return this->getKey(KeyType::restartKey);
}

void KeyboardConfig::bindKey(const KeyType& key, sf::Keyboard::Key value) {
	if (value != sf::Keyboard::Key::Unknown) {
		this->unbindSameKeys(value);
		this->setKey(key, value);
	}
}

void KeyboardConfig::unbindSameKeys(sf::Keyboard::Key& value) {
	for (auto& pair : this->keyMap)
		if (value == pair.second)
			this->unbindKey(pair.first);
}

void KeyboardConfig::unbindKey(const KeyType& key) {
	this->setKey(key, sf::Keyboard::Key::Unknown);
}

sf::Keyboard::Key KeyboardConfig::getKey(const KeyType& key) {
	return this->keyMap[key];
}

void KeyboardConfig::setKey(const KeyType& key, sf::Keyboard::Key value) {
	this->keyMap[key] = value;
}
