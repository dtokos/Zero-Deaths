#ifndef SpikeTile_hpp
#define SpikeTile_hpp

#include "./Tile.hpp"

class SpikeTile : public Tile {
public:
	using Tile::Tile;
	
	virtual void handleHazzards(Player &player);
};

#endif
