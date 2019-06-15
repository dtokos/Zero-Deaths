#include "ApplicationFactory.hpp"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1120
#define WINDOW_RATIO WINDOW_WIDTH / WINDOW_HEIGHT
#define WINDOW_CENTER_X WINDOW_WIDTH / 2
#define WINDOW_CENTER_Y WINDOW_HEIGHT / 2
#define WINDOW_NAME "Zero-Deaths"
#define FRAME_LIMIT 60

ApplicationFactory::ApplicationFactory() {
	
}

Application ApplicationFactory::make() {
	sf::RenderWindow* window = this->makeWindow();
	sf::View* view = this->makeView();
	Letterbox* letterbox = this->makeLetterbox(view);
	
	return Application(window, view, letterbox);
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
