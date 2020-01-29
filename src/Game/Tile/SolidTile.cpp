#include "SolidTile.hpp"

void SolidTile::collideX(Player &player) {}

void SolidTile::collideY(Player &player) {
	sf::FloatRect playerBody = player.getColisionBody();
	sf::FloatRect tileBody = this->body.getGlobalBounds();
	sf::FloatRect intersection;
	
	if (tileBody.intersects(playerBody, intersection)) {
		bool feetColision = intersection.contains(intersection.left, playerBody.top + playerBody.height);
		sf::Vector2f newPosition(playerBody.left, 0);
		
		if (feetColision) {
			newPosition.y = tileBody.top - playerBody.height;
		} else
			newPosition.y = tileBody.top + tileBody.height;
		
		
		player.setPosition(newPosition);
	}
}

void SolidTile::handleHazzards(Player &player) {}
