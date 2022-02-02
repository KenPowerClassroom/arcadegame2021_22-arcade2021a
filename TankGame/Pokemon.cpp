#include "Pokemon.h"

Pokemon::Pokemon()
{
	inilitalize();
}

void Pokemon::inilitalize()
{
	shape.setSize(sf::Vector2f(400, 350));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(sf::Vector2f{ 50, 500 });


	/*birdSprite.setTexture(birdTexture);
	birdSprite.setTextureRect(sf::IntRect{ 134,8,46,34 });
	birdSprite.setScale(1.5, 1.5);
	birdSprite.setPosition(100, 110);*/
}

void Pokemon::draw(sf::RenderWindow& t_window)
{
	t_window.draw(sprite);
}

void Pokemon::debugDraw(sf::RenderWindow& t_window)
{
	t_window.draw(shape);
}
