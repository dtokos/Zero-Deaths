#ifndef KeyboardControllerFactory_hpp
#define KeyboardControllerFactory_hpp

#include "../Factory.cpp"
#include "../../Config.hpp"
#include "../../PlayerController.hpp"
#include "../../GameController.hpp"
#include "Player.hpp"
#include "Game.hpp"

class KeyboardControllerFactory : public virtual ControllerFactory {
	
public:
	KeyboardControllerFactory(Config* config);
	virtual PlayerController* makePlayerController();
	virtual GameController* makeGameController();
	
private:
	Config* config;
	
};

#endif
