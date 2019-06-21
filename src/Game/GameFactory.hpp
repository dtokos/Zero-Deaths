#ifndef GameFactory_hpp
#define GameFactory_hpp

#include "Game.hpp"
#include "../Controls/Controller/Factory.hpp"

class GameFactory {
	
public:
	GameFactory(ControllerFactory* controllerFactory);
	Game* makeGame();
	
private:
	ControllerFactory* controllerFactory;
	
};

#endif
