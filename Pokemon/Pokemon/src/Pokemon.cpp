#include "Pokemon.h"

Pokemon::Pokemon()
{
	inilitalize();
}

void Pokemon::inilitalize()
{
	pokemon.setDrawableSize(300, 300);
	pokemon.setDrawableColor(sf::Color::Blue);
	controller.setPosition(100, 550);
}

void Pokemon::draw(sf::RenderWindow& t_window)
{
	pokemon.Draw(controller.position, t_window);
}

void Pokemon::update()
{
	controller.Update();
}

void Pokemon::changeType(int t_type)
{
	switch (t_type)
	{
	case 1:
		pokemon.setDrawableColor(sf::Color::Red);
		currentType = Type::Fire;
		break;
	case 2:
		pokemon.setDrawableColor(sf::Color::Green);
		currentType = Type::Grass;
		break;
	case 3:
		pokemon.setDrawableColor(sf::Color::Blue);
		currentType = Type::Water;
		break;
	case 4:
		pokemon.setDrawableColor(sf::Color::Black);
		break;
	case 5:
		pokemon.setDrawableColor(sf::Color::Magenta);
		break;
	case 6:
		pokemon.setDrawableColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}
