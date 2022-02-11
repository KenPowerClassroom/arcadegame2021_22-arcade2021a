#pragma once
#include "Drawable.h"
#include <SFML/Graphics.hpp>

class SFMLDrawable : public Drawable 
{
private:
	sf::Sprite body;
	sf::Texture tex;
	sf::RenderWindow& window;
public:
	SFMLDrawable(const char* path, sf::RenderWindow& _window);
	virtual void Draw(int xPos, int yPos);
};