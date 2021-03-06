#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <iostream>

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void update(GameState const& m_gameState);
	void render(sf::RenderWindow& m_window);
	void mouseInput(sf::Event m_event, GameState & m_gameState);

private:

	void initSprites();
	void initShapes();
	void initSexyMen();

	sf::Text m_gameplayText;
	sf::Text m_exitText;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;

	sf::Sprite m_outlineSprite;
	sf::Texture m_outlineTexture;

	sf::Sprite m_lukasfaceSprite;
	sf::Texture m_lukasfaceTexture;

	sf::Sprite m_conorfaceSprite;
	sf::Texture m_conorfaceTexture;

	sf::Sprite m_alinfaceSprite;
	sf::Texture m_alinfaceTexture;

	sf::Sprite m_patrickfaceSprite;
	sf::Texture m_patrickfaceTexture;


	sf::RectangleShape m_startRect;
	sf::RectangleShape m_optionsRect;
	sf::RectangleShape m_exitRect;
};