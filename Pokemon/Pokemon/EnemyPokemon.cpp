#include "EnemyPokemon.h"

EnemyPokemon::EnemyPokemon()
{
	textures[0].loadFromFile("resources/images/arbok.png");
	textures[1].loadFromFile("resources/images/bulbasaur.png");
	textures[2].loadFromFile("resources/images/charmander.png");
	textures[3].loadFromFile("resources/images/onix.png");
	textures[4].loadFromFile("resources/images/gengar.png");
	textures[5].loadFromFile("resources/images/squirtle.png");

	dangerTexture.loadFromFile("resources/images/danger.png");

	//Font Loading
	if (!font.loadFromFile("./resources/fonts/Gameplay.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	damageText.setFont(font);
	damageText.setCharacterSize(20U);
	damageText.setFillColor(sf::Color(88, 88, 88));

	srand(time(NULL));
}

void EnemyPokemon::Spawn()
{
	if (timer(5, respawnTimer))
	{
		int no = rand() % 6;
		int x = rand() % (1000 - 500) + 500;
		Enemy e;
		e.body.setTexture(textures[no]);
		e.body.setScale(2, 2);
		e.body.setPosition(x, 275);
		e.danger.setTexture(dangerTexture);
		e.danger.setTextureRect(sf::IntRect{0,0,242,474});
		e.danger.setScale(0.2, 0.2);
		e.danger.setPosition(e.body.getPosition().x + 70, e.body.getPosition().y - 100);

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
		respawnTimer.restart();
	}
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
	Spawn();
	pokemonHighlight();
	moveDamageText();
	attackPlayer();
	shake();
}

void EnemyPokemon::draw(sf::RenderWindow& window)
{
	for (Enemy& e : enemies)
	{
		window.draw(e.body);
		if (e.dangerous && e.alive)
		{
			window.draw(e.danger);
		}
	}
	window.draw(damageText);
}

void EnemyPokemon::pokemonHit(Type t_type, Type t_projectile, int i)
{
	float currentDamage = 0;
	float damage = 15;

	/// ========================================================================
	
	if (t_projectile == Type::Electric)
	{
		switch (t_type)
		{
		case Type::Fire:
			currentDamage = damage * 1;
			break;
		case Type::Water:
			currentDamage = damage * 2;
			break;
		case Type::Grass:
			currentDamage = damage * 0.5;
			break;
		case Type::Ghost:
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			currentDamage = damage * 1;
			break;
		case Type::Poison:
			currentDamage = damage * 1;
			break;
		}
	}
	else if (t_projectile == Type::Fire)
	{
		switch (t_type)
		{
		case Type::Fire:
			currentDamage = damage * 0.5;
			break;
		case Type::Water:
			currentDamage = damage * 0.5;
			break;
		case Type::Grass:
			currentDamage = damage * 2;
			break;
		case Type::Ghost:
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			currentDamage = damage * 0.5;
			break;
		case Type::Poison:
			currentDamage = damage * 1;
			break;
		}
	}
	else if (t_projectile == Type::Water)
	{
		switch (t_type)
		{
		case Type::Fire:
			currentDamage = damage * 2;
			break;
		case Type::Water:
			currentDamage = damage * 0.5;
			break;
		case Type::Grass:
			currentDamage = damage * 0.5;
			break;
		case Type::Ghost:
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			currentDamage = damage * 2;
			break;
		case Type::Poison:
			currentDamage = damage * 1;
			break;
		}
	}
	else if (t_projectile == Type::Grass)
	{
		switch (t_type)
		{
		case Type::Fire:
			currentDamage = damage * 0.5;
			break;
		case Type::Water:
			currentDamage = damage * 2;
			break;
		case Type::Grass:
			currentDamage = damage * 0.5;
			break;
		case Type::Ghost:
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			currentDamage = damage * 2;
			break;
		case Type::Poison:
			currentDamage = damage * 0.5;
			break;
		}
	}
	else if (t_projectile == Type::Psychic)
	{
		switch (t_type)
		{
		case Type::Fire:
			currentDamage = damage * 1;
			break;
		case Type::Water:
			currentDamage = damage * 1;
			break;
		case Type::Grass:
			currentDamage = damage * 1;
			break;
		case Type::Ghost:
			currentDamage = damage * 1;
			break;
		case Type::Rock:
			currentDamage = damage * 1;
			break;
		case Type::Poison:
			currentDamage = damage * 2;
			break;
		}
	}
	else if (t_projectile == Type::Ghost)
	{
	switch (t_type)
	{
	case Type::Fire:
		currentDamage = damage * 1;
		break;
	case Type::Water:
		currentDamage = damage * 1;
		break;
	case Type::Grass:
		currentDamage = damage * 1;
		break;
	case Type::Ghost:
		currentDamage = damage * 2;
		break;
	case Type::Rock:
		currentDamage = damage * 1;
		break;
	case Type::Poison:
		currentDamage = damage * 0.5;
		break;
	}
	}

	if (currentDamage < 10)
	{
		effectivity = "It's not very effective...";
	}
	else if (currentDamage > 20)
	{
		effectivity = "It's super effective!";
		scoreToAdd += 20;
	}
	else
	{
		effectivity = "Nice!";
		scoreToAdd += 10;
	}

	/// =========================================================================

	enemies[i].health -= currentDamage;

	if (enemies[i].health <= 0)
	{
		enemies[i].alive = false;
		scoreToAdd += 30;

		enemies[i].body.setPosition(sf::Vector2f{ -1000, -1000 });
		respawnTimer.restart();
	}

	//This makes the pokemon flash white for a second
	enemies[i].body.setColor(sf::Color::Red);
	highlightTimer.restart();

	//Resets visability of text
	visability = 255;
	setDamageText(i, currentDamage);
}

void EnemyPokemon::pokemonHighlight()
{
	for (Enemy& e : enemies)
	{
		if (timer(0.1, highlightTimer))
		{
			e.body.setColor(sf::Color::White);
		}
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

void EnemyPokemon::shake()
{
	for (Enemy& e : enemies)
	{
		if (e.dangerous)
		{
			if (e.shakeTimer.getElapsedTime().asSeconds() < 0.4f)
			{
				if (e.shakeTimer.getElapsedTime().asSeconds() < 0.1f)
				{
					e.body.move(2,0);
				}
				else if (e.shakeTimer.getElapsedTime().asSeconds() > 0.1f
					&& e.shakeTimer.getElapsedTime().asSeconds() < 0.2f)
				{
					e.body.move(-2, 0);
				}
				else if (e.shakeTimer.getElapsedTime().asSeconds() > 0.2f
					&& e.shakeTimer.getElapsedTime().asSeconds() < 0.3f)
				{
					e.body.move(2, 0);
				}
				else if (e.shakeTimer.getElapsedTime().asSeconds() > 0.3f)
				{
					e.body.move(-2, 0);
				}
			}
		}
	}
}

void EnemyPokemon::attackPlayer()
{
	for (Enemy& e : enemies)
	{
		//This is for when the danger mark comes up
		if (timer(3, e.readyTimer) &&
			e.alive)
		{
			if (!e.dangerous) e.shakeTimer.restart();
			e.dangerous = true;

			//This is for when it resets and hurts the player
			if (timer(5, e.attackTimer))
			{
				e.attacking = true;
				e.dangerous = false;
				e.readyTimer.restart();
				e.attackTimer.restart();
				e.shakeTimer.restart();
			}
		}
	}
}

bool EnemyPokemon::playerRecieveDamage()
{
	for (Enemy& e : enemies)
	{
		if (e.attacking)
		{
			e.attacking = false;
			return true;
		}
	}
	return false;
}
