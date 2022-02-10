#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pokemon.h"
#include "projectile.h"
#include "Thor/Vectors.hpp"

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

	void loadTextures();
	void collisions();
	sf::Vector2f getMousePosition();
	void shootProjectile();

	//Mouse
	sf::Vector2f mousePosition{ 0,0 };
	sf::Vector2f mouseDirection{ 0,0 };

	//Player Pokemon
	Pokemon playerPokemon[6];
	int currentPokemon{ 0 };

	//Projectiles
	projectile attackProjectile;

	//Bush
	sf::RectangleShape bushShape;

	//Misc
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

