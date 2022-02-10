#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Drawable.h"
#include "PokemonController.h"

class Pokemon
{
public:
	Pokemon(Drawable& _pokemon);
	void inilitalize();
	void draw();

	int currentPokemon{ 0 };
private:
	
	PokemonController controller;
	Drawable& pokemon;
};

#endif