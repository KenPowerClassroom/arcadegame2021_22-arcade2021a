#pragma once
#include "Drawable.h"
#include "Input.h"
#include <SFML/Graphics.hpp>

class Pokemon
{
public:
	Pokemon(Drawable& _pokemon, Input& _input);
	void inilitalize();
	void draw(sf::RenderWindow& t_window);
	void update();
	void pollInput();

	void setPokemon(int);

private:
	int currentPokemon{ 0 };

	sf::Sprite pokemon;
	sf::Texture	texture;

	Input& input;
};