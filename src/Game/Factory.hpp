#ifndef GameFactory_hpp
#define GameFactory_hpp

#include <tuple>
#include "Controllers/Factory.hpp"
#include "Assets/AssetManager.hpp"
#include "./Game.hpp"

class GameFactory {
	
public:
	GameFactory(ControllerFactory* controllerFactory, AssetManager* assetManager);
	Game* makeGame();
	
private:
	ControllerFactory* controllerFactory;
	AssetManager* assetManager;
	
};

#endif
