#pragma once
#include "Drawable.h"
#include "Input.h"

class Pokemon
{
public:
	Pokemon(Drawable& _pokemon, Input& _input);
	void inilitalize();
	void draw();
	void update();
	void pollInput();

	void setPokemon(int);

private:
	int currentPokemon{ 0 };

	Drawable& pokemon;
	Input& input;
};