#include "Pokemon.h"

Pokemon::Pokemon(Drawable& _pokemon, Input& _input)
	: pokemon{ _pokemon }, input{ _input }
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

void Pokemon::pollInput()
{
	if (input.KeyPressed(input.Space))
	{
		std::cout << "Space pressed\n";
	}
}
