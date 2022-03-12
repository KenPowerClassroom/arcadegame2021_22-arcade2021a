#pragma once
#include <SFML/Graphics.hpp>
#include <random>

struct Enemy
{
	sf::Sprite body;
	bool alive = true;
};

class EnemyPokemon
{
public:
	EnemyPokemon();
	void Spawn();
	int AmountOnScreen() { return enemies.size(); }

	void update();
	void draw(sf::RenderWindow& window);

private:
	std::vector<Enemy> enemies;
	
	sf::Texture textures[6];
};

