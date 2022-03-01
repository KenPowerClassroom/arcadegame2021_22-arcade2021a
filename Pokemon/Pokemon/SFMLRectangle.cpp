#include "SFMLRectangle.h"

SFMLRectangle::SFMLRectangle(int width, int height, sf::RenderWindow& _window)
	: window{ _window }, body{sf::Vector2f(width, height)}
{
}

void SFMLRectangle::Draw(int xPos, int yPos)
{
	body.setPosition(xPos, yPos);
	window.draw(body);
}

void SFMLRectangle::SetColour(sf::Color c)
{
	body.setFillColor(c);
}
