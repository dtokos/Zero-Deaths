#ifndef StatusBar_hpp
#define StatusBar_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "./StatusBar/LevelInfo.hpp"
#include "./StatusBar/Stats.hpp"
#include "./StatusBar/Stopwatch.hpp"

class StatusBar {
	
public:
	StatusBar(sf::Font& font, int maxLevel, sf::FloatRect bounds);
	void update(const float& deltaTime);
	void setLevel(const int& levelNumber);
	void incrementRestarts();
	void stopStopwatch();
	void draw(sf::RenderWindow& window);
	
private:
	LevelInfo levelInfo;
	Stats stats;
	Stopwatch stopwatch;
	sf::FloatRect bounds;
	
	void alignLevelInfo();
	void alignStats();
	void alignStopwatch();
	float leftMargin();
	float centerX();
	float rightMargin();
	
};

#endif
