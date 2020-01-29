#include "Factory.hpp"

GameFactory::GameFactory(ControllerFactory* controllerFactory, AssetManager* assetManager) :
	controllerFactory(controllerFactory),
	assetManager(assetManager) {
	
}

Game* GameFactory::makeGame() {
	Player* player = new Player(this->assetManager->playerTexture());
	LevelParser* levelParser = new LevelParser(std::tuple<int, int>{48, 27}, std::tuple<int, int>{40, 40}, this->assetManager->levelTexture());
	LevelLoader* levelLoader = new LevelLoader(levelParser);
	LevelManager* levelManager = new LevelManager(levelLoader);
	PlayerController* playerController = this->controllerFactory->makePlayerController();
	GameController* gameController = this->controllerFactory->makeGameController();
	GameState* gameState = new GameState(player, levelManager, gameController);
	GameLoop* gameLoop = new GameLoop(player, levelManager, playerController);
	StatusBar* statusBar = new StatusBar(this->assetManager->sansationFont(), 30, sf::FloatRect(0, 1080, 1920, 40));
	GameRenderer* gameRenderer = new GameRenderer(player, levelManager, statusBar);
	
	return new Game(gameState, gameLoop, gameRenderer);
}
