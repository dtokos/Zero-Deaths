#ifndef Stats_hpp
#define Stats_hpp

#include <sstream>
#include <SFML/Graphics/Text.hpp>

class Stats {
	
public:
	Stats(sf::Font& font);
	void setRestarts(const int& restarts);
	
private:
	sf::Text text;
	std::stringstream textStream;
	
	void clearTextStream();
	
};

#endif
