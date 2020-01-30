#include "SolidTile.hpp"

void SolidTile::collideX(Player &player) {
	sf::FloatRect playerBody = player.getColisionBody();
	sf::FloatRect tileBody = this->body.getGlobalBounds();
	sf::FloatRect intersection;
	
	if (tileBody.intersects(playerBody, intersection)) {
		bool rightColision = intersection.contains(tileBody.left, intersection.top);
		sf::Vector2f newPosition(0, playerBody.top);
		
		if (rightColision) {
			newPosition.x = tileBody.left - playerBody.height;
		} else
			newPosition.x = tileBody.left + tileBody.width;
		
		player.setPosition(newPosition);
	}
}

void SolidTile::collideY(Player &player) {
	sf::FloatRect playerBody = player.getColisionBody();
	sf::FloatRect tileBody = this->body.getGlobalBounds();
	sf::FloatRect intersection;
	
	if (tileBody.intersects(playerBody, intersection)) {
		bool feetColision = intersection.contains(intersection.left, tileBody.top);
		sf::Vector2f newPosition(playerBody.left, 0);
		
		if (feetColision) {
			newPosition.y = tileBody.top - playerBody.height;
			player.resetJump();
		} else
			newPosition.y = tileBody.top + tileBody.height;
		
		player.setVelocityY(0);
		player.setPosition(newPosition);
	}
}

void SolidTile::handleHazzards(Player &player) {}
