#ifndef GameKeyboardController_hpp
#define GameKeyboardController_hpp

#include <SFML/Window/Keyboard.hpp>
#include "../Game.hpp"
#include "./Config.hpp"

class GameKeyboardController : public virtual GameController {

public:
	GameKeyboardController(KeyboardConfig* config);
	virtual void apply(GameControls& game);
	
private:
	KeyboardConfig* config;
	bool isKeyPressed(const sf::Keyboard::Key& key);
};

#endif
