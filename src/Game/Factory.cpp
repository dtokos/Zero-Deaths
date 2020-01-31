#include "Factory.hpp"

GameFactory::GameFactory(std::string resourcePath, ControllerFactory* controllerFactory, AssetManager* assetManager) :
	resourcePath(resourcePath),
	controllerFactory(controllerFactory),
	assetManager(assetManager) {
	
}

Game* GameFactory::makeGame() {
	Player* player = new Player(this->assetManager->playerTexture());
	
	LevelParser* levelParser = new LevelParser(std::tuple<int, int>{48, 27}, std::tuple<int, int>{40, 40}, this->assetManager->levelTexture());
	LevelLoader* levelLoader = new LevelLoader(this->resourcePath, levelParser);
	LevelManager* levelManager = new LevelManager(levelLoader);
	
	PlayerController* playerController = this->controllerFactory->makePlayerController();
	StatusBar* statusBar = new StatusBar(this->assetManager->sansationFont(), 30, sf::FloatRect(0, 1080, 1920, 40));
	
	GameController* gameController = this->controllerFactory->makeGameController();
	GameState* gameState = new GameState(player, levelManager, gameController, statusBar);
	GameLoop* gameLoop = new GameLoop(player, levelManager, playerController, statusBar);
	GameRenderer* gameRenderer = new GameRenderer(player, levelManager, statusBar);
	
	return new Game(gameState, gameLoop, gameRenderer);
}
