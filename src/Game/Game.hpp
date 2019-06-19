#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "GameState.hpp"
#include "GameLoop.hpp"
#include "GameRenderer.hpp"

class Game {
	
public:
	Game(GameState* gameState, GameLoop* gameLoop, GameRenderer* gameRenderer);
	void handleInputs();
	void update(const float& deltaTime);
	void draw(const sf::RenderWindow& window);
	
private:
	GameState* gameState;
	GameLoop* gameLoop;
	GameRenderer* gameRenderer;
	
};

#endif
