#include "SFMLDrawable.h"

SFMLDrawable::SFMLDrawable(const char* path, sf::RenderWindow& _window)
	: window{ _window }
{
	tex.loadFromFile(path);
	body.setTexture(tex);
}

void SFMLDrawable::Draw(int xPos, int yPos)
{
	body.setPosition(xPos, yPos);
	window.draw(body);
}

void SFMLDrawable::ChangeTexture(const char* path)
{
	tex.loadFromFile(path);
	body.setTexture(tex);
}
