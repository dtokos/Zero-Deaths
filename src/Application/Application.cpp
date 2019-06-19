#include "Application.hpp"

Application::Application(sf::RenderWindow* window, sf::View* view, Letterbox* letterbox) :
	window(window),
	view(view),
	letterbox(letterbox) {

}

Application::~Application() {
	delete this->window;
	delete this->view;
	delete this->letterbox;
}

void Application::run() {
	while (this->window->isOpen()) {
		this->handleEvents();
		this->window->clear();
		this->window->setView(*this->view);
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
