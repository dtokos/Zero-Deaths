#ifndef PlayerController_hpp
#define PlayerController_hpp

#include "../Player/PlayerControls.hpp"

class PlayerController {
	
public:
	virtual void apply(PlayerControls& player) = 0;
	
};

#endif
