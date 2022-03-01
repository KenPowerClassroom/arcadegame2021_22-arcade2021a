#pragma once
#include "Drawable.h"
#include <SFML/Graphics.hpp>

class SFMLRectangle : public Drawable
{
private:
	sf::RectangleShape body;
	sf::RenderWindow& window;
public:
	SFMLRectangle(int width, int height, sf::RenderWindow& _window);
	virtual void Draw(int xPos, int yPos);
	void SetColour(sf::Color c); 
	virtual void ChangeTexture(const char* path) {}
};

