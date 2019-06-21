#ifndef GameFactory_hpp
#define GameFactory_hpp

#include "Game.hpp"

class GameFactory {
	
public:
	GameFactory();
	Game* makeGame();
	
};

#endif
