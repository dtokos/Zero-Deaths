#include "Factory.hpp"

GameFactory::GameFactory(ControllerFactory* controllerFactory) :
	controllerFactory(controllerFactory) {
	
}

Game* GameFactory::makeGame() {
	Player* player = new Player();
	LevelLoader* levelLoader = new LevelLoader();
	LevelManager* levelManager = new LevelManager(levelLoader);
	PlayerController* playerController = this->controllerFactory->makePlayerController();
	GameController* gameController = this->controllerFactory->makeGameController();
	GameState* gameState = new GameState(player, levelManager, gameController);
	GameLoop* gameLoop = new GameLoop(player, levelManager, playerController);
	GameRenderer* gameRenderer = new GameRenderer(player, levelManager);
	
	return new Game(gameState, gameLoop, gameRenderer);
}
