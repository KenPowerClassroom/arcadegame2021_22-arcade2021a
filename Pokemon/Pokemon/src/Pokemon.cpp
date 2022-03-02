#include "Pokemon.h"

Pokemon::Pokemon(Drawable& _pokemon, Input& _input)
	: pokemon{ _pokemon }, input{ _input }
{
	inilitalize();
}

void Pokemon::inilitalize()
{
}

void Pokemon::draw()
{
	pokemon.Draw(0, 651);
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
		pokemon.ChangeTexture("resources/images/pikachu.png");
	}
	else if (num == 1)
	{
		currentPokemon = 1;
		pokemon.ChangeTexture("resources/images/firepikachu.png");
	}
	else if (num == 2)
	{
		currentPokemon = 2;
		pokemon.ChangeTexture("resources/images/waterpikachu.png");
	}
}
