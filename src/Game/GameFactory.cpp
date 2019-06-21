#include "GameFactory.hpp"

GameFactory::GameFactory() {
	
}

Game* GameFactory::makeGame() {
	Player* player = new Player();
	LevelLoader* levelLoader = new LevelLoader();
	LevelManager* levelManager = new LevelManager(levelLoader);
	GameState* gameState = new GameState(player, levelManager);
	GameLoop* gameLoop = new GameLoop(player, levelManager);
	GameRenderer* gameRenderer = new GameRenderer(player, levelManager);
	
	return new Game(gameState, gameLoop, gameRenderer);
}
