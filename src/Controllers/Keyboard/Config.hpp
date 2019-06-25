#ifndef Config_hpp
#define Config_hpp

#include <map>
#include <SFML/Window.hpp>

class KeyboardConfig {

public:
	KeyboardConfig(sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key jumpKey, sf::Keyboard::Key restartKey);
	void merge(KeyboardConfig& config);
	sf::Keyboard::Key right();
	sf::Keyboard::Key left();
	sf::Keyboard::Key jump();
	sf::Keyboard::Key restart();
	
private:
	enum KeyType {
		leftKey,
		rightKey,
		jumpKey,
		restartKey
	};
	
	std::map<KeyType, sf::Keyboard::Key> keyMap;
	
	void bindKey(const KeyType& key, sf::Keyboard::Key value);
	void unbindSameKeys(sf::Keyboard::Key& value);
	void unbindKey(const KeyType& key);
	sf::Keyboard::Key getKey(const KeyType& key);
	void setKey(const KeyType& key, sf::Keyboard::Key value);
	
};

#endif
