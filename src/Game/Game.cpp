#include "Game.hpp"

Game::Game(GameState* state, GameLoop* loop, GameRenderer* renderer) :
	state(state),
	loop(loop),
	renderer(renderer) {
	
}

void Game::handleInputs() {
	this->state->handleInputs();
	this->loop->handleInputs();
}

void Game::update(const float& deltaTime) {
	this->loop->update(deltaTime);
	this->state->update();
}

void Game::draw(const sf::RenderWindow& window) {
	this->renderer->draw(window);
}
