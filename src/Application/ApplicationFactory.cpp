#include "ApplicationFactory.hpp"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1120
#define WINDOW_RATIO (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT
#define WINDOW_CENTER_X WINDOW_WIDTH / 2
#define WINDOW_CENTER_Y WINDOW_HEIGHT / 2
#define WINDOW_NAME "Zero-Deaths"
#define FRAME_LIMIT 60

#define CONFIG_NAME "bindings.cfg"

ApplicationFactory::ApplicationFactory(std::string resourcePath) :
	gameFactory(this->makeGameFactory(resourcePath)) {
		
}

Application ApplicationFactory::make() {
	sf::RenderWindow* window = this->makeWindow();
	sf::View* view = this->makeView();
	Letterbox* letterbox = this->makeLetterbox(view);
	Game* game = this->gameFactory.makeGame();
	
	return Application(window, view, letterbox, game);
}

sf::RenderWindow* ApplicationFactory::makeWindow() {
	sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::RenderWindow* window = new sf::RenderWindow(videoMode, WINDOW_NAME);
	window->setFramerateLimit(FRAME_LIMIT);
	
	return window;
}

sf::View* ApplicationFactory::makeView() {
	sf::Vector2f center(WINDOW_CENTER_X, WINDOW_CENTER_Y);
	sf::Vector2f size(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::View* view = new sf::View(center, size);
	
	return view;
}

Letterbox* ApplicationFactory::makeLetterbox(sf::View* view) {
	return new Letterbox(view, WINDOW_RATIO);
}

KeyboardConfig* ApplicationFactory::defaultConfig() {
	return new KeyboardConfig(sf::Keyboard::Key::Right, sf::Keyboard::Key::Left, sf::Keyboard::Key::Up, sf::Keyboard::Key::R);
};

KeyboardConfig* ApplicationFactory::loadConfig(std::string resourcePath) {
	KeyboardConfigLoader loader;
	KeyboardConfig* defaultConfig = this->defaultConfig();
	KeyboardConfig* userConfig = loader.load(resourcePath + CONFIG_NAME);
	
	defaultConfig->merge(*userConfig);
	
	delete userConfig;
	
	return defaultConfig;
}

GameFactory ApplicationFactory::makeGameFactory(std::string resourcePath) {
	KeyboardConfig* config = this->loadConfig(resourcePath);
	ControllerFactory* controllerFactory = new KeyboardControllerFactory(config);
	AssetManager* assetManager = new AssetManager(resourcePath);
	
	return GameFactory(resourcePath, controllerFactory, assetManager);
}
