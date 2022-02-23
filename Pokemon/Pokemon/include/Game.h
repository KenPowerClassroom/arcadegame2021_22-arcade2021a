#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pokemon.h"
#include "EnemyPokemon.h"
#include "PokemonBar.h"
#include "projectile.h"
#include "SFMLDrawable.h"
#include <memory>

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processKeyReleases(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	bool timer(float t_desiredTime, sf::Clock t_timer);

	void loadTextures();
	void collisions();
	Vector2 getMousePosition();

	//Mouse
	Vector2 mousePosition;

	//Player Pokemon
	Pokemon playerPokemon;
	PokemonBar pokemonBar;
	int currentPokemon{ 1 };

	//Player attack
	const int MAX_ATTACKS{ 10 };
	projectile playerAttack[10];
	int currentAttack{ 0 };

	//Enemy Pokemon
	EnemyPokemon enemyPokemon;

	//SFMLDrawable playerPokenonSprite;
	//std::unique_ptr<Pokemon> playerPokemon = std::make_unique<Pokemon>(playerPokenonSprite);
	

	//Bush
	sf::RectangleShape bushShape;

	//Misc
	sf::RenderWindow m_window; // main SFML window
	sf::Clock attackTimer;

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

