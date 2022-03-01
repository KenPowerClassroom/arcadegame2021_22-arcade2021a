#pragma once

#include "SFMLDrawable.h"
#include "Gizmos.h"
#include <iostream>
#include "Types.h"

using namespace Gizmos;

class EnemyPokemon
{
public:
	EnemyPokemon();
	void inilitalize();
	void draw(sf::RenderWindow& t_window);
	void update();
	void spawnPokemon();
	void pokemonHit(Type t_type);
	void pokemonHighlight();
	bool timer(float t_desiredTime, sf::Clock t_timer);
	void setDamageText();
	void moveDamageText();

	sf::FloatRect getBounds() { return pokemon.getBounds(); }

private:
	SFMLDrawable pokemon;
	Vector2 position;
	Vector2 startingPosition{ 700, 200 };
	sf::Clock respawnTimer;
	sf::Clock highlightTimer;
	sf::Font font;
	sf::Text damageText;
	std::string effectivity;
	int visability{ 255 };

	int health{ 50 };
	int damage{ 10 };
	int currentDamage{ 0 };
	bool alive{ true };
};

