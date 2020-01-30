#ifndef Tile_hpp
#define Tile_hpp

#include <SFML/Graphics.hpp>
#include "../Player/Player.hpp"

class Tile {
	
public:
	Tile(sf::Texture& texture, sf::IntRect& bounds, int textureOffset);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::FloatRect getCollisionBody();
	
	virtual void collideX(Player &player);
	virtual void collideY(Player &player);
	
	virtual void handleHazzards(Player &player);
	
protected:
	sf::Sprite body;
	
};

#endif
