#include "GameRenderer.hpp"

GameRenderer::GameRenderer(Player* player, CurrentLevel* level) :
	player(player),
	level(level) {
	
}

void GameRenderer::draw(sf::RenderWindow& window) {
	this->player->draw(window);
	this->level->current()->draw(window);
}
