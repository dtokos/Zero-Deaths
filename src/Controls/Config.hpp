#ifndef Config_hpp
#define Config_hpp

#include <map>
#include <SFML/Window.hpp>

class Config {

public:
	Config(sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Keyboard::Key jumpKey, sf::Keyboard::Key restartKey);
	void merge(Config& config);
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
	
	void bindKey(sf::Keyboard::Key value, const KeyType& destination);
	void unbindSameKeys(sf::Keyboard::Key& value);
	void unbindKey(const KeyType& destination);
	sf::Keyboard::Key getKey(const KeyType& destination);
	void setKey(sf::Keyboard::Key value, const KeyType& destination);
	
};

#endif
