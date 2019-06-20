#ifndef GameKeyboardController_hpp
#define GameKeyboardController_hpp

#include <SFML/Window/Keyboard.hpp>
#include "../../GameController.hpp"
#include "../../../Game/GameControls.hpp"
#include "../../Config.hpp"

class GameKeyboardController : public virtual GameController {

public:
	GameKeyboardController(Config* config);
	virtual void apply(GameControls& game);
	
private:
	Config* config;
	bool isKeyPressed(const sf::Keyboard::Key& key);
};

#endif
