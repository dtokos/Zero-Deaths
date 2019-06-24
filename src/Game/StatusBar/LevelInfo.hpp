#ifndef LevelInfo_hpp
#define LevelInfo_hpp

#include <sstream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class LevelInfo {
	
public:
	LevelInfo(sf::Font& font, int fontSize, int maxLevel);
	void setLevel(const int& levelNumber);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getBounds();
	void setPosition(float x, float y);
	
private:
	sf::Text text;
	std::stringstream textStream;
	int maxLevel;
	
	void clearTextStream();
};

#endif
