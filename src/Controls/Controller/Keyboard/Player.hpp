#ifndef PlayerKeyboardController_hpp
#define PlayerKeyboardController_hpp

#include <SFML/Window/Keyboard.hpp>
#include "../../PlayerController.hpp"
#include "../../../Player/PlayerControls.hpp"
#include "../../Config.hpp"

class PlayerKeyboardController : public virtual PlayerController {

public:
	PlayerKeyboardController(Config* config);
	virtual void apply(PlayerControls& player);
	
private:
	Config* config;
	bool isKeyPressed(const sf::Keyboard::Key& key);
	PlayerMoveType getMoveType();
	unsigned char calculateMoveType();
	PlayerMoveType convertMoveType(unsigned char moveType);
	
};

#endif
