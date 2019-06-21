#include "Application.hpp"

#define MAX_DELTA_TIME 1.0f/45.0f

Application::Application(sf::RenderWindow* window, sf::View* view, Letterbox* letterbox, Game* game) :
	window(window),
	view(view),
	clock(sf::Clock()),
	letterbox(letterbox),
	game(game),
	deltaTime(0) {

}

Application::~Application() {
	delete this->window;
	delete this->view;
	delete this->letterbox;
}

void Application::run() {
	while (this->window->isOpen()) {
		this->updateDeltaTime();
		this->handleEvents();
		this->window->clear();
		this->window->setView(*this->view);
		this->game->handleInputs();
		this->game->update(this->deltaTime);
		this->game->draw(*this->window);
		this->window->display();
	}
}

void Application::handleEvents() {
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
				
			case sf::Event::Resized:
				this->letterbox->apply(event.size.width, event.size.height);
				break;
		}
	}
}

void Application::updateDeltaTime() {
	this->deltaTime = this->limitDeltaTime(this->getDeltaTime());
}

float Application::getDeltaTime() {
	return this->clock.restart().asSeconds();
}

float Application::limitDeltaTime(float deltaTime) {
	return std::min(deltaTime, MAX_DELTA_TIME);
}
