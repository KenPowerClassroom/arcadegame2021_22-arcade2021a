#include "Pokemon.h"

Pokemon::Pokemon(Drawable& _pokemon)
	: pokemon{ _pokemon }
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
