#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class PokemonBar
{
public:
	PokemonBar();
	void initialize();
	void draw(sf::RenderWindow& t_window);
	void selectPokemon(int t_type);

private:

	sf::RectangleShape pokemon[6];
	sf::Sprite pokemonSprite[6];
	sf::Texture	texture[6];
	sf::Vector2f position[6];
	const float size{ 75 };
};