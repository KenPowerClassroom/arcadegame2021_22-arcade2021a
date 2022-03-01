#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Pokemon.h"
#include "SFMLDrawable.h"
#include "SFMLInput.h"

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

	//Mouse
	sf::Vector2f mousePosition{ 0,0 };

	//Player Pokemon
	SFMLDrawable playerSprite;
	SFMLInput playerInput;
	std::unique_ptr<Pokemon> player;


	//Bush
	sf::RectangleShape bushShape;

	//Misc
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

