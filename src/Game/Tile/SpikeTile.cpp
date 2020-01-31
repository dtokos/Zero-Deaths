#include "SpikeTile.hpp"

#define TRESHOLD 2

void SpikeTile::handleHazzards(Player &player) {
	sf::FloatRect playerBody = player.getColisionBody();
	sf::FloatRect tileBody = this->body.getGlobalBounds();
	sf::FloatRect intersection;
	
	if (tileBody.intersects(playerBody, intersection) && (intersection.width > TRESHOLD || intersection.height > TRESHOLD))
		player.kill();
}
