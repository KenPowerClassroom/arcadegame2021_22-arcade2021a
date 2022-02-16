#pragma once
#include "Drawable.h"
#include "Input.h"
#include "PokemonController.h"
#include <iostream>

class Pokemon
{
public:
	Pokemon(Drawable& _pokemon, Input& _input);
	void inilitalize();
	void draw();
	void update();
	void pollInput();

	int currentPokemon{ 0 };
private:
	
	PokemonController controller;
	Drawable& pokemon;
	Input& input;
};