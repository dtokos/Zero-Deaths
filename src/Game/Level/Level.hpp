#ifndef Level_hpp
#define Level_hpp

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Tile/Tile.hpp"

class Level {

public:
	Level(int levelNumber, std::vector<Tile*> tiles, unsigned short startTileIndex, unsigned short finishTileIndex, sf::Vector2f tileSize, sf::Vector2i levelSize);
	void draw(sf::RenderWindow& window);
	int number();
	Tile* startTile();
	Tile* finishTile();
	Tile *tileAt(sf::Vector2f position);
	
private:
	int levelNumber;
	std::vector<Tile*> tiles;
	sf::Vector2f tileSize;
	sf::Vector2i levelSize;
	unsigned short startTileIndex;
	unsigned short finishTileIndex;
	
};

#endif
