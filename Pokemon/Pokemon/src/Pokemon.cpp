#include "Pokemon.h"

Pokemon::Pokemon(Drawable& _pokemon, Input& _input)
	: pokemon{ _pokemon }, input{ _input }
{
	inilitalize();
}

void Pokemon::inilitalize()
{
}

void Pokemon::draw()
{
	pokemon.Draw(controller.position.x, controller.position.y);
}

void Pokemon::update()
{
	controller.Update();
}

void Pokemon::pollInput()
{
	if (input.KeyPressed(input.Space))
	{
		std::cout << "Space pressed\n";
	}
}
