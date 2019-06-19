#include "Game.hpp"

Game::Game(GameState* gameState, GameLoop* gameLoop, GameRenderer* gameRenderer) :
	gameState(gameState),
	gameLoop(gameLoop),
	gameRenderer(gameRenderer) {
	
}
