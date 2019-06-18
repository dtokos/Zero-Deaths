#ifndef AssetNotFound_hpp
#define AssetNotFound_hpp

#include <string>
#include <exception>

class AssetNotFound : virtual public std::exception {
	
public:
	AssetNotFound(const std::string& assetName);
	virtual const char* what() const throw();
	std::string assetName;
	
};

#endif
