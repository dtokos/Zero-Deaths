#ifndef Config_hpp
#define Config_hpp

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
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key jumpKey;
	sf::Keyboard::Key restartKey;
	
	void setKey(sf::Keyboard::Key value, sf::Keyboard::Key* destination);
	bool isAlreadyAssigned(sf::Keyboard::Key& value);
	
};

#endif
