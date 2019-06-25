#ifndef GameFactory_hpp
#define GameFactory_hpp

#include "Controllers/Factory.hpp"
#include "./Game.hpp"

class GameFactory {
	
public:
	GameFactory(ControllerFactory* controllerFactory);
	Game* makeGame();
	
private:
	ControllerFactory* controllerFactory;
	
};

#endif
