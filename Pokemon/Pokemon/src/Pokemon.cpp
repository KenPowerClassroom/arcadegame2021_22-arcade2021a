#include "Pokemon.h"

int Pokemon::pokemonCreated = 1;

Pokemon::Pokemon()
{
	inilitalize();
	pokemonCreated++;
}

void Pokemon::inilitalize()
{
	shape.setSize(sf::Vector2f(400, 350));
	shape.setPosition(sf::Vector2f{ 50, 500 });

	switch (pokemonCreated)
	{
	case 1:
		shape.setFillColor(sf::Color::Blue);
		break;
	case 2:
		shape.setFillColor(sf::Color::Green);
		break;
	case 3:
		shape.setFillColor(sf::Color::Black);
		break;
	case 4:
		shape.setFillColor(sf::Color::Red);
		break;
	case 5:
		shape.setFillColor(sf::Color::Magenta);
		break;
	case 6:
		shape.setFillColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
	
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
