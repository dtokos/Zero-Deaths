#include "SpringTile.hpp"

#define SPRING_FORCE -26

void SpringTile::collideX(Player &player) {
	sf::FloatRect playerBody = player.getColisionBody();
	sf::FloatRect tileBody = this->body.getGlobalBounds();
	sf::FloatRect intersection;
	
	if (tileBody.intersects(playerBody, intersection)) {
		bool rightColision = intersection.contains(tileBody.left, intersection.top);
		sf::Vector2f newPosition(0, playerBody.top);
		
		if (rightColision) {
			newPosition.x = floor(tileBody.left - playerBody.width);
		} else
			newPosition.x = ceil(tileBody.left + tileBody.width);
		
		player.setPosition(newPosition);
	}
}

void SpringTile::collideY(Player &player) {
	sf::FloatRect playerBody = player.getColisionBody();
	sf::FloatRect tileBody = this->body.getGlobalBounds();
	sf::FloatRect intersection;
	
	if (tileBody.intersects(playerBody, intersection)) {
		bool feetColision = intersection.contains(intersection.left, tileBody.top);
		sf::Vector2f newPosition(playerBody.left, 0);
		
		if (feetColision) {
			newPosition.y = floor(tileBody.top - playerBody.height);
			player.resetJump();
			player.setVelocityY(SPRING_FORCE);
		} else {
			newPosition.y = ceil(tileBody.top + tileBody.height);
			player.setVelocityY(0);
		}
		
		player.setPosition(newPosition);
	}
}

