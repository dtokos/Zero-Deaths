#ifndef SpringTile_hpp
#define SpringTile_hpp

#include "./Tile.hpp"

class SpringTile : public Tile {
	using Tile::Tile;
	
	virtual void collideX(Player &player);
	virtual void collideY(Player &player);
};

#endif
