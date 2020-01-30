#include "Tile.hpp"

Tile::Tile(sf::Texture& texture, sf::IntRect& bounds, int textureOffset) :
	body(texture, sf::IntRect(textureOffset * bounds.width, 0, bounds.width, bounds.height)) {
		this->body.setPosition(bounds.left, bounds.top);
}

void Tile::draw(sf::RenderWindow &window) {
	window.draw(this->body);
}

sf::Vector2f Tile::getPosition() {
	return this->body.getPosition();
}

sf::FloatRect Tile::getCollisionBody() {
	return this->body.getGlobalBounds();
}

void Tile::collideX(Player &player) {}
void Tile::collideY(Player &player) {}

void Tile::handleHazzards(Player &player) {}
