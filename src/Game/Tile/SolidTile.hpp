#ifndef SolidTile_hpp
#define SolidTile_hpp

#include "./Tile.hpp"

class SolidTile : public Tile {
	using Tile::Tile;
	
	virtual void collideX(Player &player);
	virtual void collideY(Player &player);
	
	virtual void handleHazzards(Player &player);
};

#endif
