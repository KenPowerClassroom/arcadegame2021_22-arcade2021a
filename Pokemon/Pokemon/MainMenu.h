#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"

class MainMenu
{
public:
	MainMenu(sf::Font& hudFont);
	~MainMenu();

	void update(GameState const& m_gameState);
	void render(sf::RenderWindow& m_window);

private:
	sf::Text m_gameplayText;
	sf::Text m_exitText;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;

	sf::RectangleShape m_boxRect;
	sf::RectangleShape m_gameplayRect;
	sf::RectangleShape m_exitRect;
};