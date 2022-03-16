#include "EnemyPokemon.h"

EnemyPokemon::EnemyPokemon()
{
	textures[0].loadFromFile("resources/images/arbok.png");
	textures[1].loadFromFile("resources/images/bulbasaur.png");
	textures[2].loadFromFile("resources/images/charmander.png");
	textures[3].loadFromFile("resources/images/onix.png");
	textures[4].loadFromFile("resources/images/gengar.png");
	textures[5].loadFromFile("resources/images/squirtle.png");
	//Font Loading
	if (!font.loadFromFile("./resources/fonts/Gameplay.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	damageText.setFont(font);
	damageText.setCharacterSize(20U);
	damageText.setFillColor(sf::Color(88, 88, 88));
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

	switch (no)
	{
	case 0:
		e.type = Type::Poison;
		break;
	case 1:
		e.type = Type::Grass;
		break;
	case 2:
		e.type = Type::Fire;
		break;
	case 3:
		e.type = Type::Rock;
		break;
	case 4:
		e.type = Type::Ghost;
		break;
	case 5:
		e.type = Type::Water;
		break;
	}
	enemies.push_back(e);
}

void EnemyPokemon::checkCollisions(projectile& t_attack)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].body.getGlobalBounds().intersects(t_attack.getSprite().getGlobalBounds()) &&
			t_attack.getActive())
		{
			pokemonHit(enemies[i].type, t_attack.getType(), i);
			t_attack.setActive(false);
		}
	}
}

void EnemyPokemon::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Spawn();
	}
	pokemonHighlight();
	moveDamageText();
}

void EnemyPokemon::draw(sf::RenderWindow& window)
{
	for (Enemy& e : enemies)
	{
		window.draw(e.body);
	}
	window.draw(damageText);
}

void EnemyPokemon::pokemonHit(Type t_type, Type t_projectile, int i)
{
	float currentDamage = 0;
	float damage = 25;

	/// ========================================================================
	
	if (t_projectile == Type::Electric)
	{
		switch (t_type)
		{
		case Type::Fire:
			effectivity = "Nice!";
			currentDamage = damage * 1;
			break;
		case Type::Water:
			effectivity = "It's super effective!";
			currentDamage = damage * 2;
			break;
		case Type::Grass:
			effectivity = "It's not very effective...";
			currentDamage = damage * 0.5;
			break;
		case Type::Ghost:
			effectivity = "It's not very effective...";
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			effectivity = "Nice!";
			currentDamage = damage * 1;
			break;
		case Type::Poison:
			effectivity = "Nice!";
			currentDamage = damage * 1;
			break;
		}
	}
	// WORK IN PROGRESS
	else if (t_projectile == Type::Fire)
	{
		switch (t_type)
		{
		case Type::Fire:
			effectivity = "It's not very effective...";
			currentDamage = damage * 0.5;
			break;
		case Type::Water:
			effectivity = "It's super effective!";
			currentDamage = damage * 2;
			break;
		case Type::Grass:
			effectivity = "It's not very effective...";
			currentDamage = damage * 0.5;
			break;
		case Type::Ghost:
			effectivity = "It's not very effective...";
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			effectivity = "Nice!";
			currentDamage = damage * 1;
			break;
		case Type::Poison:
			effectivity = "Nice!";
			currentDamage = damage * 1;
			break;
		}
	}
	else if (t_projectile == Type::Water)
	{

	}

	/// =========================================================================

	enemies[i].health -= currentDamage;

	if (enemies[i].health <= 0)
	{
		enemies[i].alive = false;

		enemies[i].body.setPosition(sf::Vector2f{ -1000, -1000 });
		respawnTimer.restart();
	}

	//This makes the pokemon flash white for a second
	enemies[i].body.setColor(sf::Color::White);
	highlightTimer.restart();
	//Resets visability of text
	visability = 255;
	setDamageText(i, currentDamage);
}

void EnemyPokemon::pokemonHighlight()
{
	if (timer(0.1, highlightTimer))
	{
		//pokemon.setDrawableColor(sf::Color::Red);
	}
}

bool EnemyPokemon::timer(float t_desiredTime, sf::Clock t_timer)
{
	sf::Time timePasted = t_timer.getElapsedTime();
	float secondsPasted = timePasted.asSeconds();
	float desiredTimer = t_desiredTime;

	if (secondsPasted >= desiredTimer)
	{
		t_timer.restart();
		return true;
	}
	return false;
}

void EnemyPokemon::setDamageText(int i, float currentDamage)
{
	damageText.setPosition(enemies[i].body.getPosition().x - 100, enemies[i].body.getPosition().y - 25);
	damageText.setString(std::to_string((int)currentDamage) + " Damage! " + effectivity);
}

void EnemyPokemon::moveDamageText()
{
	damageText.move(0, -0.5);
	damageText.setFillColor(sf::Color(0, 0, 0, visability));
	if (visability >= 2)
	{
		visability -= 2;
	}
}