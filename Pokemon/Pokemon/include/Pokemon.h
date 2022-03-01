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
	void draw(sf::RenderWindow& t_window);
	void update();
	void pollInput();

private:

	Type currentType{ Type::Fire };
	PokemonController controller;
	Drawable& pokemon;
	Input& input;
};