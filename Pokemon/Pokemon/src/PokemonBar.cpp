#include "PokemonBar.h"

PokemonBar::PokemonBar()
{
	initialize();
}

void PokemonBar::initialize()
{
	double x = 25;
	double y = 300;

	for (int i = 0; i < 6; i++)
	{
		pokemon[i].setDrawableSize(size, size);
		pokemon[i].setDrawableColor(sf::Color::Magenta);
		position[i] = { x, y };

		x += 100;

		if (i == 2)
		{
			x = 50;
			y += 100;
		}
	}
	pokemon[0].setDrawableColor(sf::Color::Black);
}

void PokemonBar::draw(sf::RenderWindow& t_window)
{
	for (size_t i = 0; i < 6; i++)
	{
		pokemon[i].Draw(position[i], t_window);
	}
}

void PokemonBar::selectPokemon(int t_type)
{
	for (size_t i = 0; i < 6; i++)
	{
		pokemon[i].setDrawableColor(sf::Color::Magenta);
		if (i == t_type - 1)
		{ 
			pokemon[i].setDrawableColor(sf::Color::Black);
		}
	}
}


