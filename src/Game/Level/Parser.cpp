#include "Parser.hpp"

#define LEVEL_NUMBER_SIZE sizeof(int)
#define INDEX_SIZE sizeof(unsigned short)
#define TILE_SIZE 0.5 * sizeof(unsigned char)

#define TILE_BACKGROUND 0
#define TILE_SOLID 1
#define TILE_SPIKE_BOTTOM 2
#define TILE_BACKGROUND_WHITE 3
#define TILE_BACKGROUND_WHITE_RIGHT 4
#define TILE_BACKGROUND_WHITE_LEFT 5
#define TILE_SPIKE_RIGHT 6
#define TILE_SPIKE_TOP 7
#define TILE_SPIKE_LEFT 8
#define TILE_SPRING 9
#define TILE_BACKGROUND_FINISH 10

LevelParser::LevelParser(std::tuple<int, int> levelSize, std::tuple<int, int> textureSize, sf::Texture& tileTexture) :
	levelSize(levelSize),
	textureSize(textureSize),
	tileTexture(tileTexture) {
	
}

Level* LevelParser::parse(const std::vector<unsigned char>& levelData) {
	std::vector<unsigned char>::const_iterator dataIterator = levelData.begin();
	this->checkSize(levelData.size());
	this->parseLevelNumber(dataIterator);
	this->parseStartIndex(dataIterator);
	this->parseFinishIndex(dataIterator);
	this->parseTiles(dataIterator);
	
	return new Level(
		this->levelNumber,
		this->tiles,
		this->startIndex,
		this->finishIndex,
		sf::Vector2f(std::get<0>(this->textureSize), std::get<1>(this->textureSize)),
		sf::Vector2i(std::get<0>(this->levelSize), std::get<1>(this->levelSize))
	);
}

void LevelParser::checkSize(int levelDataSize) {
	if (this->expectedSize() != levelDataSize)
		throw LevelParsingException("Level size does not match.");
}

int LevelParser::expectedSize() {
	return LEVEL_NUMBER_SIZE + INDEX_SIZE * 2 + std::get<0>(this->levelSize) * std::get<1>(this->levelSize) * TILE_SIZE;
}

void LevelParser::parseLevelNumber(std::vector<unsigned char>::const_iterator& dataIterator) {
	this->levelNumber = this->parseNumber<int>(dataIterator);
}

void LevelParser::parseStartIndex(std::vector<unsigned char>::const_iterator& dataIterator) {
	this->startIndex = this->parseIndex(dataIterator);
}

void LevelParser::parseFinishIndex(std::vector<unsigned char>::const_iterator& dataIterator) {
	this->finishIndex = this->parseIndex(dataIterator);
}

void LevelParser::parseTiles(std::vector<unsigned char>::const_iterator& dataIterator) {
	this->tiles.clear();
	int tileCount = std::get<0>(this->levelSize) * std::get<1>(this->levelSize);
	
	for (int i = 0, tileIndex = 0; i < tileCount * TILE_SIZE; i++)
		this->parseTwoTiles(dataIterator, tileIndex);
}

void LevelParser::parseTwoTiles(std::vector<unsigned char>::const_iterator& dataIterator, int& tileIndex) {
	unsigned char twoTiles = this->parseNumber<unsigned char>(dataIterator);
	unsigned char firstTile = this->parseFirstTileNibble(twoTiles);
	unsigned char secondTile = this->parseSecondTileNibble(twoTiles);
	
	this->parseTile(firstTile, tileIndex++);
	this->parseTile(secondTile, tileIndex++);
}

void LevelParser::parseTile(unsigned char tileNumber, int tileIndex) {
	int column = tileIndex % std::get<0>(this->levelSize);
	int row = tileIndex / std::get<0>(this->levelSize);
	int x = column * std::get<0>(this->textureSize);
	int y = row * std::get<1>(this->textureSize);
	sf::IntRect bounds(x, y, std::get<0>(this->textureSize), std::get<1>(this->textureSize));
	
	switch (tileNumber) {
		/*case TILE_BACKGROUND:
		case TILE_BACKGROUND_WHITE:
		case TILE_BACKGROUND_WHITE_LEFT:
		case TILE_BACKGROUND_WHITE_RIGHT:
		case TILE_BACKGROUND_FINISH:
			std::cout << "BackgroundTile\n";
			// add new BackgroundTile
			break;*/
			
		case TILE_SOLID:
			this->tiles.push_back(new SolidTile(this->tileTexture, bounds, tileNumber));
			break;
			
		/*case TILE_SPIKE_TOP:
		case TILE_SPIKE_LEFT:
		case TILE_SPIKE_RIGHT:
		case TILE_SPIKE_BOTTOM:
			std::cout << "SpikeTile\n";
			// add new SpikeTile
			break;
			
		case TILE_SPRING:
			std::cout << "SpringTile\n";
			// add new SpringTile
			break;*/
			
		default:
			this->tiles.push_back(new Tile(this->tileTexture, bounds, tileNumber));
			//throw LevelParsingException("Unknown tile number");
	}
}

unsigned char LevelParser::parseFirstTileNibble(unsigned char twoTiles) {
	return twoTiles >> 4;
}

unsigned char LevelParser::parseSecondTileNibble(unsigned char twoTiles) {
	return twoTiles & 0x0f;
}

unsigned short LevelParser::parseIndex(std::vector<unsigned char>::const_iterator& dataIterator) {
	unsigned short index = this->parseNumber<unsigned short>(dataIterator);
	int total = std::get<0>(this->levelSize) * std::get<1>(this->levelSize);
	
	if (index >= total)
		throw LevelParsingException("Index is out of bounds");
	
	return index;
}

template <typename T>
T LevelParser::parseNumber(std::vector<unsigned char>::const_iterator& dataIterator) {
	T result = 0;
	
	for (int i = 0; i < sizeof(T); i++, dataIterator++) {
		result = result << 8;
		result += *dataIterator;
	}
	
	return result;
}
