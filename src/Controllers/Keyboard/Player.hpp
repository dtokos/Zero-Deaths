#ifndef PlayerKeyboardController_hpp
#define PlayerKeyboardController_hpp

#include <SFML/Window/Keyboard.hpp>
#include "../Player.hpp"
#include "./Config.hpp"

class PlayerKeyboardController : public virtual PlayerController {

public:
	PlayerKeyboardController(KeyboardConfig* config);
	virtual void apply(PlayerControls& player);
	
private:
	KeyboardConfig* config;
	bool isKeyPressed(const sf::Keyboard::Key& key);
	PlayerMoveType getMoveType();
	char calculateMoveType();
	PlayerMoveType convertMoveType(char moveType);
	
};

#endif
