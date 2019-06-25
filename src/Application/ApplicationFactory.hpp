#ifndef ApplicationFactory_hpp
#define ApplicationFactory_hpp

#include "./Application.hpp"
#include "./Letterbox.hpp"
#include "Game/Factory.hpp"
#include "Controllers/Keyboard/Config/Loader.hpp"
#include "Controllers/Keyboard/Factory.hpp"

class ApplicationFactory {
	
public:
	ApplicationFactory();
	Application make();
	
private:
	GameFactory gameFactory;
	
	sf::RenderWindow* makeWindow();
	sf::View* makeView();
	Letterbox* makeLetterbox(sf::View* view);
	KeyboardConfig* defaultConfig();
	KeyboardConfig* loadConfig();
	GameFactory makeGameFactory();
	
};

#endif
