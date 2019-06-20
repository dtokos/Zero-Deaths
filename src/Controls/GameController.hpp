#ifndef GameController_hpp
#define GameController_hpp

#include "../Game/GameControls.hpp"

class GameController {

public:
	virtual void apply(GameControls& game) = 0;
	
};

#endif
