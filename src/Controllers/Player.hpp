#ifndef PlayerController_hpp
#define PlayerController_hpp

#include "Game/Controls/Player.hpp"

class PlayerController {
	
public:
	virtual void apply(PlayerControls& player) = 0;
	
};

#endif
