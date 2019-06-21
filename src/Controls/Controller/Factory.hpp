#ifndef ControllerFactory_hpp
#define ControllerFactory_hpp

#include "../PlayerController.hpp"
#include "../GameController.hpp"

class ControllerFactory {
	
public:
	virtual PlayerController* makePlayerController() = 0;
	virtual GameController* makeGameController() = 0;

};

#endif
