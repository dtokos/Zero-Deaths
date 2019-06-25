#ifndef KeyboardControllerFactory_hpp
#define KeyboardControllerFactory_hpp

#include "../Factory.cpp"
#include "./Config.hpp"
#include "./Player.hpp"
#include "./Game.hpp"

class KeyboardControllerFactory : public virtual ControllerFactory {
	
public:
	KeyboardControllerFactory(KeyboardConfig* config);
	virtual PlayerController* makePlayerController();
	virtual GameController* makeGameController();
	
private:
	KeyboardConfig* config;
	
};

#endif
