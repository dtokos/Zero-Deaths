#include "Renderer.hpp"

GameRenderer::GameRenderer(Player* player, CurrentLevel* level) :
	player(player),
	level(level) {
	
}

void GameRenderer::draw(const sf::RenderWindow& window) {
	this->player->draw(window);
	this->level->current()->draw(window);
}
