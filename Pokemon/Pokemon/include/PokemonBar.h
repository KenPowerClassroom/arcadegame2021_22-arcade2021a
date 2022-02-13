#pragma once

#include "SFMLDrawable.h"
#include "Gizmos.h"

using namespace Gizmos;

class PokemonBar
{
public:
	PokemonBar();
	void initialize();
	void draw(sf::RenderWindow& t_window);
	void selectPokemon(int t_type);

private:

	SFMLDrawable pokemon[6];
	Vector2 position[6];
	const float size{ 75 };
};

