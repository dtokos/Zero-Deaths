#include "Renderer.hpp"

GameRenderer::GameRenderer(Player* player, CurrentLevel* level, StatusBar* statusBar) :
	player(player),
	level(level),
	statusBar(statusBar) {
	
}

void GameRenderer::draw(sf::RenderWindow& window) {
	this->level->current()->draw(window);
	this->player->draw(window);
	this->statusBar->draw(window);
}
