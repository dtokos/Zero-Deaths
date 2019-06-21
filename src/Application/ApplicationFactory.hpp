#ifndef ApplicationFactory_hpp
#define ApplicationFactory_hpp

#include "Application.hpp"
#include "Letterbox.hpp"
#include "../Controls/Config/Loader.hpp"
#include "../Controls/Config.hpp"
#include "../Game/GameFactory.hpp"

class ApplicationFactory {
	
public:
	ApplicationFactory();
	Application make();
	
private:
	GameFactory gameFactory;
	
	sf::RenderWindow* makeWindow();
	sf::View* makeView();
	Letterbox* makeLetterbox(sf::View* view);
	Config* defaultConfig();
	Config* loadConfig();
	
};

#endif
