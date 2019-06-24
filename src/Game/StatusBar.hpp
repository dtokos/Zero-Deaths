#ifndef StatusBar_hpp
#define StatusBar_hpp

#include <SFML/Graphics/Font.hpp>
#include "StatusBar/LevelInfo.hpp"
#include "StatusBar/Stats.hpp"
#include "StatusBar/Stopwatch.hpp"

class StatusBar {
	
public:
	StatusBar(sf::Font& font, int maxLevel);
	void update(const float& deltaTime);
	void setLevel(const int& levelNumber);
	void setRestarts(const int& restarts);
	
private:
	LevelInfo levelInfo;
	Stats stats;
	Stopwatch stopwatch;
	
};

#endif
