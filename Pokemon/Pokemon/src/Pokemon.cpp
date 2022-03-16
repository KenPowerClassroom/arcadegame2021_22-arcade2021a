#include "Pokemon.h"

Pokemon::Pokemon(Drawable& _pokemon, Input& _input)
	: input{ _input }
{
	inilitalize();
}

void Pokemon::inilitalize()
{
	texture.loadFromFile("resources/images/PlayerPokemon/pikachu.png");
	pokemon.setTexture(texture);
	pokemon.setPosition(0, 651);
	pokemon.setScale(3, 3);
}

void Pokemon::draw(sf::RenderWindow& t_window)
{
	t_window.draw(pokemon);
}

void Pokemon::update()
{
}

void Pokemon::pollInput()
{
}

void Pokemon::setPokemon(int num)
{
	if (num == 0)
	{
		currentPokemon = 0;
		texture.loadFromFile("resources/images/PlayerPokemon/pikachu.png");
	}
	else if (num == 1)
	{
		currentPokemon = 1;
		texture.loadFromFile("resources/images/PlayerPokemon/charizard.png");
	}
	else if (num == 2)
	{
		currentPokemon = 2;
		texture.loadFromFile("resources/images/PlayerPokemon/blastoise.png");
	}
	else if (num == 3)
	{
		currentPokemon = 3;
		texture.loadFromFile("resources/images/PlayerPokemon/venusaur.png");
	}
}
