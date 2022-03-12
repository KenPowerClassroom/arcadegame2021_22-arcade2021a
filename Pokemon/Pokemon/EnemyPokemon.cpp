#include "EnemyPokemon.h"

EnemyPokemon::EnemyPokemon()
{
	textures[0].loadFromFile("resources/images/arbok.png");
	textures[1].loadFromFile("resources/images/bulbasaur.png");
	textures[2].loadFromFile("resources/images/charmander.png");
	textures[3].loadFromFile("resources/images/onix.png");
	textures[4].loadFromFile("resources/images/gengar.png");
	textures[5].loadFromFile("resources/images/squirtle.png");
	Spawn();
	srand(time(NULL));
}

void EnemyPokemon::Spawn()
{
	int no = rand() % 6;
	int x = rand() % (1000 - 500) + 500;
	Enemy e;
	e.body.setTexture(textures[no]);
	e.body.setScale(2, 2);
	e.body.setPosition(x, 275);
	enemies.push_back(e);
}

void EnemyPokemon::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Spawn();
	}
}

void EnemyPokemon::draw(sf::RenderWindow& window)
{
	for (Enemy& e : enemies)
	{
		window.draw(e.body);
	}
}
