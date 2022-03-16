#include "PokemonBar.h"

PokemonBar::PokemonBar()
{
	initialize();
}

void PokemonBar::initialize()
{
	float x = 35;
	float y = 400;

	for (int i = 0; i < 6; i++)
	{
		pokemon[i].setSize(sf::Vector2f{ size, size });
		pokemon[i].setFillColor(sf::Color::Color(255,255,255,100));
		pokemon[i].setOutlineColor(sf::Color::Black);
		pokemon[i].setOutlineThickness(5);
		position[i] = { x, y };
		pokemon[i].setPosition(position[i]);

		x += 100;

		if (i == 2)
		{
			x = 50;
			y += 100;
		}
	}
	pokemon[0].setOutlineColor(sf::Color::Red);

	//Font Loading
	texture[0].loadFromFile("./resources/images/Portraits/P1.png");
	texture[1].loadFromFile("./resources/images/Portraits/P2.png");
	texture[2].loadFromFile("./resources/images/Portraits/P3.png");
	texture[3].loadFromFile("./resources/images/Portraits/P4.png");
	texture[4].loadFromFile("./resources/images/Portraits/P4.png");
	texture[5].loadFromFile("./resources/images/Portraits/P4.png");

	for (size_t i = 0; i < 6; i++)
	{
		pokemonSprite[i].setTexture(texture[i]);
		pokemonSprite[i].setTextureRect(sf::IntRect{ 0,0,600,600 });
		pokemonSprite[i].setScale(0.12, 0.12);
		pokemonSprite[i].setPosition(position[i]);
	}
}

void PokemonBar::draw(sf::RenderWindow& t_window)
{
	for (size_t i = 0; i < 6; i++)
	{
		t_window.draw(pokemon[i]);
		t_window.draw(pokemonSprite[i]);
	}
}

void PokemonBar::selectPokemon(int t_type)
{
	for (size_t i = 0; i < 6; i++)
	{
		pokemon[i].setOutlineColor(sf::Color::Black);
		if (i == t_type - 1)
		{
			pokemon[i].setOutlineColor(sf::Color::Red);
		}
	}
}