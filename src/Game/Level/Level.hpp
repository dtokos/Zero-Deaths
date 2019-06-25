#ifndef Level_hpp
#define Level_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Tile/Tile.hpp"

class Level {

public:
	Level();
	void draw(const sf::RenderWindow& window);
	Tile* startTile();
	Tile* finishTile();
	
};

#endif
