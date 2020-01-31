#include "Loader.hpp"

LevelLoader::LevelLoader(std::string resourcePath, LevelParser* parser) :
	resourcePath(resourcePath),
	parser(parser) {
	
}

Level* LevelLoader::load(const int& levelNumber) {
	std::vector<unsigned char> levelContents = this->loadLevelContents(levelNumber);
	
	return this->parser->parse(levelContents);
}

std::vector<unsigned char> LevelLoader::loadLevelContents(const int& levelNumber) {
	std::string levelPath = this->getLevelPath(levelNumber);
	std::ifstream levelFile(levelPath, std::ios::in | std::ios::binary);
	
	return std::vector<unsigned char>(std::istreambuf_iterator<char>(levelFile), std::istreambuf_iterator<char>());
}

std::string LevelLoader::getLevelPath(const int& levelNumber) {
	return this->resourcePath + "./levels/" + std::to_string(levelNumber) + ".zdl";
}
