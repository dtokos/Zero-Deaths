#ifndef Stopwatch_hpp
#define Stopwatch_hpp

#include <math.h>
#include <sstream>
#include <iomanip>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Stopwatch {
	
public:
	Stopwatch(sf::Font& font, int fontSize);
	void update(const float& deltaTime);
	void stop();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getBounds();
	void setPosition(float x, float y);
	
private:
	sf::Text text;
	float miliSeconds;
	int seconds;
	int minutes;
	int hours;
	bool isRunning;
	std::stringstream textStream;
	
	void updateTime(const float& deltaTime);
	void updateText();
	void appendNumber(const int& number, char fillWidth = 2);
	void appendString(const std::string& string);
	void clearTextStream();
};

#endif
