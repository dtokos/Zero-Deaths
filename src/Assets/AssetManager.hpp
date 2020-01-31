#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "./AssetNotFound.hpp"

class AssetManager {

public:
	AssetManager(std::string resoucePath);
	sf::Texture& playerTexture();
	sf::Texture& levelTexture();
	sf::Font& sansationFont();
	
private:
	enum TextureType {
		player,
		level,
	};
	
	enum FontType {
		sansation,
	};
	
	std::string resourcePath;
	
	std::map<TextureType, sf::Texture> textureCache;
	static const std::map<TextureType, std::string> textureNameMap;
	std::map<FontType, sf::Font> fontCache;
	static const std::map<FontType, std::string> fontNameMap;
	
	sf::Texture& getTexture(const TextureType& type);
	bool hasCachedTexture(const TextureType& type);
	sf::Texture loadTexture(const TextureType& type);
	const std::string& getTextureName(const TextureType& type);
	void cacheTexture(const TextureType& type, sf::Texture texture);
	sf::Texture& getCachedTexture(const TextureType& type);
	
	sf::Font& getFont(const FontType& type);
	bool hasCachedFont(const FontType& type);
	sf::Font loadFont(const FontType& type);
	const std::string& getFontName(const FontType& type);
	void cacheTexture(const FontType& type, sf::Font font);
	sf::Font& getCachedFont(const FontType& type);
};

#endif
