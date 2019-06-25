#ifndef ConfigParser_hpp
#define ConfigParser_hpp

#include <string>
#include <sstream>
#include <map>
#include <SFML/Window.hpp>
#include "../Config.hpp"

class KeyboardConfigParser {
	
public:
	KeyboardConfigParser();
	KeyboardConfig* parse(std::stringstream& configString);
	
private:
	std::map<std::string, sf::Keyboard::Key> bindings;
	static const std::map<std::string, sf::Keyboard::Key> keyMap;
	
	void mapToKey(std::string& key, std::string& value);
	bool isBindingSupported(std::string& key);
	bool isKeySupported(std::string& key);
	void setBinding(std::string& binding, std::string& key);
	sf::Keyboard::Key getBindingKey(const std::string& binding);
	sf::Keyboard::Key right();
	sf::Keyboard::Key left();
	sf::Keyboard::Key jump();
	sf::Keyboard::Key restart();
};

#endif
