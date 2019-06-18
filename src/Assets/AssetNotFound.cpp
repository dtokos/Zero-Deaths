#include "AssetNotFound.hpp"

AssetNotFound::AssetNotFound(const std::string& assetName) :
	assetName(assetName) {
	
}

const char* AssetNotFound::what() const throw() {
	return "Asset was not found with specified filename";
}
