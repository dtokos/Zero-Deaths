#ifndef Application_hpp
#define Application_hpp

#include <SFML/Graphics.hpp>
#include "Letterbox.hpp"

class Application {

public:
	Application(sf::RenderWindow* window, sf::View* view, Letterbox* letterbox);
	void run();
	
private:
	sf::RenderWindow* window;
	sf::View* view;
	Letterbox* letterbox;

};

#endif
