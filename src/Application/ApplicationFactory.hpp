#ifndef ApplicationFactory_hpp
#define ApplicationFactory_hpp

#include "./Application.hpp"
#include "./Letterbox.hpp"
#include "Game/Factory.hpp"
#include "Assets/AssetManager.hpp"
#include "Controllers/Keyboard/Config/Loader.hpp"
#include "Controllers/Keyboard/Factory.hpp"

class ApplicationFactory {
	
public:
	ApplicationFactory(std::string resourcePath);
	Application make();
	
private:
	GameFactory gameFactory;
	
	sf::RenderWindow* makeWindow();
	sf::View* makeView();
	Letterbox* makeLetterbox(sf::View* view);
	KeyboardConfig* defaultConfig();
	KeyboardConfig* loadConfig();
	GameFactory makeGameFactory(std::string resourcePath);
	
};

#endif
