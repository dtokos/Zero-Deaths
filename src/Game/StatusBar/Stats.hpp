#ifndef Stats_hpp
#define Stats_hpp

#include <sstream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Stats {
	
public:
	Stats(sf::Font& font, int fontSize);
	void setRestarts(const int& restarts);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getBounds();
	void setPosition(float x, float y);
	
private:
	sf::Text text;
	std::stringstream textStream;
	
	void clearTextStream();
	
};

#endif
