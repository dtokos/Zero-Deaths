#ifndef LevelInfo_hpp
#define LevelInfo_hpp

#include <sstream>
#include <SFML/Graphics/Text.hpp>

class LevelInfo {
	
public:
	LevelInfo(sf::Font& font, int maxLevel);
	void setLevel(const int& levelNumber);
	
private:
	sf::Text text;
	std::stringstream textStream;
	int maxLevel;
	
	void clearTextStream();
};

#endif
