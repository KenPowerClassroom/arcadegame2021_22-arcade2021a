#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Pokemon.h"
#include "SFMLDrawable.h"
#include "SFMLRectangle.h"
#include "SFMLInput.h"
#include "projectile.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void loadTextures();
	void collisions();

	//Player Pokemon
	SFMLDrawable playerSprite;
	SFMLInput playerInput;
	std::unique_ptr<Pokemon> player;
	//bullets
	SFMLDrawable bulletSprites[10];
	projectile bullets[10];
	int currentBullet = 0;
	sf::Clock cooldown;

	//Rectangles
	SFMLRectangle bushShape;
	SFMLRectangle selectedPokemon[3];

	//Misc
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

