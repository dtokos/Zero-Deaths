#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "./State.hpp"
#include "./Loop.hpp"
#include "./Renderer.hpp"

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
