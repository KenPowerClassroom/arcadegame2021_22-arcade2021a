#pragma once
#include "SFMLDrawable.h"
#include "PokemonController.h"
#include "Gizmos.h"
#include "Types.h"

using namespace Gizmos;

class Pokemon
{
public:
	Pokemon();
	void inilitalize();
	void draw(sf::RenderWindow& t_window);
	void update();
	void changeType(int t_type);
	Type getType() { return currentType; }

private:

	Type currentType{ Type::Fire };
	PokemonController controller;
	SFMLDrawable pokemon;

};