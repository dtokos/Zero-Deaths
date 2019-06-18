#include "AssetManager.hpp"

#define ASSETS "./assets/"
#define TEXTURES ASSETS "textures/"
#define FONTS ASSETS "fonts/"
#define PLAYER_TEXTURE TEXTURES "player.png"
#define LEVEL_TEXTURE TEXTURES "level.png"
#define SANSATION_FONT FONTS "sansation.ttf"

AssetManager::AssetManager() {
	
}

sf::Texture& AssetManager::playerTexture() {
	return this->getTexture(TextureType::player);
}

sf::Texture& AssetManager::levelTexture() {
	return this->getTexture(TextureType::level);
}

sf::Font& AssetManager::sansationFont() {
	return this->getFont(FontType::sansation);
}

const std::map<AssetManager::TextureType, std::string> AssetManager::textureNameMap = {
	{TextureType::player, PLAYER_TEXTURE},
	{TextureType::level, LEVEL_TEXTURE},
};

const std::map<AssetManager::FontType, std::string> AssetManager::fontNameMap = {
	{FontType::sansation, SANSATION_FONT},
};

sf::Texture& AssetManager::getTexture(const TextureType& type) {
	if (!this->hasCachedTexture(type)) {
		sf::Texture texture = this->loadTexture(type);
		this->cacheTexture(type, texture);
	}
	
	return this->getCachedTexture(type);
}

bool AssetManager::hasCachedTexture(const TextureType& type) {
	return this->textureCache.count(type);
}

sf::Texture AssetManager::loadTexture(const TextureType& type) {
	const std::string& textureName = this->getTextureName(type);
	sf::Texture texure;
	
	if (!texure.loadFromFile(textureName))
		throw AssetNotFound(textureName);
	
	return texure;
}

const std::string& AssetManager::getTextureName(const TextureType& type) {
	return this->textureNameMap.at(type);
}

void AssetManager::cacheTexture(const TextureType& type, sf::Texture texture) {
	this->textureCache[type] = texture;
}

sf::Texture& AssetManager::getCachedTexture(const TextureType& type) {
	return this->textureCache[type];
}

sf::Font& AssetManager::getFont(const FontType& type) {
	if (!this->hasCachedFont(type)) {
		sf::Font font = this->loadFont(type);
		this->cacheTexture(type, font);
	}
	
	return this->getCachedFont(type);
}

bool AssetManager::hasCachedFont(const FontType& type) {
	return this->fontCache.count(type);
}

sf::Font AssetManager::loadFont(const FontType& type) {
	const std::string& fontName = this->getFontName(type);
	sf::Font font;
	
	if (!font.loadFromFile(fontName))
		throw AssetNotFound(fontName);
	
	return font;
}

const std::string& AssetManager::getFontName(const FontType& type) {
	return this->fontNameMap.at(type);
}

void AssetManager::cacheTexture(const FontType& type, sf::Font font) {
	this->fontCache[type] = font;
}

sf::Font& AssetManager::getCachedFont(const FontType& type) {
	return this->fontCache[type];
}

