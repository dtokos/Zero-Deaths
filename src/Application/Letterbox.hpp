#ifndef Letterbox_hpp
#define Letterbox_hpp

#include <SFML/Graphics.hpp>

class Letterbox {
	
public:
	Letterbox(sf::View* view, float desiredSizeRatio);
	void apply(float currentWidth, float currentHeight);
	
private:
	sf::View* view;
	float desiredSizeRatio;
	
	sf::FloatRect calculateViewport(float currentWidth, float currentHeight);
	float calculateSizeRatio(float width, float height);
	bool shouldAddHorizontalSpacing(float currentSizeRatio);
	float calculatePosition(float currentSize);
};

#endif
