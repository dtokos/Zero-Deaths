#ifndef LevelParser_hpp
#define LevelParser_hpp

#include <vector>
#include <tuple>
#include "./Level.hpp"
#include "../Tile/SolidTile.hpp"
#include "../Tile/SpikeTile.hpp"
#include "../Tile/SpringTile.hpp"
#include "./Parser/ParsingException.hpp"

class LevelParser {
	
public:
	LevelParser(std::tuple<int, int> levelSize, std::tuple<int, int> textureSize, sf::Texture& tileTexture);
	Level* parse(const std::vector<unsigned char>& levelData);
	
private:
	std::tuple<int, int> levelSize;
	std::tuple<int, int> textureSize;
	int levelNumber;
	unsigned short startIndex;
	unsigned short finishIndex;
	std::vector<Tile *> tiles;
	sf::Texture& tileTexture;
	
	void checkSize(int levelDataSize);
	int expectedSize();
	void parseLevelNumber(std::vector<unsigned char>::const_iterator& dataIterator);
	void parseStartIndex(std::vector<unsigned char>::const_iterator& dataIterator);
	void parseFinishIndex(std::vector<unsigned char>::const_iterator& dataIterator);
	void parseTiles(std::vector<unsigned char>::const_iterator& dataIterator);
	void parseTwoTiles(std::vector<unsigned char>::const_iterator& dataIterator, int& tileIndex);
	void parseTile(unsigned char tileNumber, int tileIndex);
	unsigned char parseFirstTileNibble(unsigned char twoTiles);
	unsigned char parseSecondTileNibble(unsigned char twoTiles);
	unsigned short parseIndex(std::vector<unsigned char>::const_iterator& dataIterator);
	template<typename T>
	T parseNumber(std::vector<unsigned char>::const_iterator& dataIterator);
	
};

#endif
