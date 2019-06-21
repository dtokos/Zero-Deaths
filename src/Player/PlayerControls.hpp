#ifndef PlayerControls_hpp
#define PlayerControls_hpp

#include "PlayerMoveType.hpp"

class PlayerControls {
	
public:
	virtual void move(const PlayerMoveType& type) = 0;
	virtual void jump() = 0;
	
};

#endif
