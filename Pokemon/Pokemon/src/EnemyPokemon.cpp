#include "EnemyPokemon.h"

EnemyPokemon::EnemyPokemon()
{
	inilitalize();
}

void EnemyPokemon::inilitalize()
{
	pokemon.setDrawableSize(150, 150);
	pokemon.setDrawableColor(sf::Color::Red);
	position = { 700, 200 };

	//Font Loading
	if (!font.loadFromFile("./resources/fonts/Gameplay.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	damageText.setFont(font);
	damageText.setCharacterSize(20U);
	damageText.setFillColor(sf::Color(88, 88, 88));
}

void EnemyPokemon::draw(sf::RenderWindow& t_window)
{
	pokemon.Draw(position, t_window);
	t_window.draw(damageText);
}

void EnemyPokemon::update()
{
	spawnPokemon();
	pokemonHighlight();
	moveDamageText();
}

void EnemyPokemon::spawnPokemon()
{
	if (!alive &&
		timer(5, respawnTimer))
	{
		position = startingPosition;
		alive = true;
		health = 50;
	}
}

void EnemyPokemon::pokemonHit(Type t_type)
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
	default:
		break;
	}

	health -= currentDamage;

	if (health <= 0)
	{
		alive = false;
		position = { -1000, -1000 };
		respawnTimer.restart();
	}

	//This makes the pokemon flash white for a second
	pokemon.setDrawableColor(sf::Color::White);
	highlightTimer.restart();
	//Resets visability of text
	visability = 255;
	setDamageText();
}

void EnemyPokemon::pokemonHighlight()
{
	if (timer(0.1, highlightTimer))
	{
		pokemon.setDrawableColor(sf::Color::Red);
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

void EnemyPokemon::setDamageText()
{
	damageText.setPosition(position.x - 100, position.y - 25);
	damageText.setString(std::to_string(currentDamage) + " Damage! " + effectivity);
}

void EnemyPokemon::moveDamageText()
{
	damageText.move(0, -0.5);
	damageText.setFillColor(sf::Color(0,0,0,visability));
	if (visability >= 2)
	{
		visability -= 2;
	}
}
