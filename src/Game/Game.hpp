#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "GameState.hpp"
#include "GameLoop.hpp"
#include "GameRenderer.hpp"

class Game {
	
public:
	Game(GameState* state, GameLoop* loop, GameRenderer* renderer);
	void handleInputs();
	void update(const float& deltaTime);
	void draw(const sf::RenderWindow& window);
	
private:
	GameState* state;
	GameLoop* loop;
	GameRenderer* renderer;
	
};

#endif
