#ifndef ApplicationFactory_hpp
#define ApplicationFactory_hpp

#include "Application.hpp"
#include "Letterbox.hpp"

class ApplicationFactory {
	
public:
	ApplicationFactory();
	Application make();
	
private:
	sf::RenderWindow* makeWindow();
	sf::View* makeView();
	Letterbox* makeLetterbox(sf::View* view);
	
};

#endif
