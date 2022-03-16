#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "projectile.h"
#include "Types.h"
#include <iostream>

struct Enemy
{
	sf::Sprite body;
	bool alive = true;
	bool dangerous = false;
	bool attacking = false;
	float health{ 50 };
	Type type{ Type::Fire };
	sf::Sprite danger;
	sf::Clock readyTimer;
	sf::Clock attackTimer;
};

class EnemyPokemon
{
public:
	EnemyPokemon();
	void Spawn();
	int AmountOnScreen() { return enemies.size(); }
	void checkCollisions(projectile& t_attack);
	void pokemonHighlight();
	bool timer(float t_desiredTime, sf::Clock t_timer);
	void setDamageText(int i, float currentDamage);
	void pokemonHit(Type t_type, Type t_projectile, int i);
	void moveDamageText();
	void attackPlayer();
	bool playerRecieveDamage();

	void update();
	void draw(sf::RenderWindow& window);

private:
	std::vector<Enemy> enemies;
	int visability{ 255 };
	sf::Texture textures[6];
	std::string effectivity;
	sf::Clock respawnTimer;
	sf::Clock highlightTimer;
	sf::Font font;
	sf::Text damageText;
	sf::Texture dangerTexture;
};

