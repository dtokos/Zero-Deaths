#include "Level.hpp"

Level::Level(int levelNumber, std::vector<Tile*> tiles, unsigned short startTileIndex, unsigned short finishTileIndex, sf::Vector2f tileSize, sf::Vector2i levelSize) :
	levelNumber(levelNumber),
	tiles(tiles),
	startTileIndex(startTileIndex),
	finishTileIndex(finishTileIndex),
	tileSize(tileSize),
	levelSize(levelSize) {
	
}

void Level::draw(sf::RenderWindow& window) {
	for (Tile* tile : this->tiles)
		tile->draw(window);
}

int Level::number() {
	return this->levelNumber;
}

Tile* Level::startTile() {
	return this->tiles[this->startTileIndex];
}

Tile* Level::finishTile() {
	return this->tiles[this->finishTileIndex];
}

Tile *Level::tileAt(sf::Vector2f position) {
	int col = position.x / this->tileSize.x;
	int row = position.y / this->tileSize.y;
	
	return this->tiles[row * this->levelSize.x + col];
}
