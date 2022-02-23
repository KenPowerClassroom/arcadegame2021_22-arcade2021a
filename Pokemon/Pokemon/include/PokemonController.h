#pragma once
#include "Gizmos.h"

class PokemonController
{
public:
	PokemonController();

	void Update();
	void setPosition(float t_x, float t_y);

	Gizmos::Vector2 position;
};