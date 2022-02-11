#pragma once
#include "Drawable.h"
#include "PokemonController.h"

class Pokemon
{
public:
	Pokemon(Drawable& _pokemon);
	void inilitalize();
	void draw();
	void update();

	int currentPokemon{ 0 };
private:
	
	PokemonController controller;
	Drawable& pokemon;
};