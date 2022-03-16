#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Pokemon.h"
#include "EnemyPokemon.h"
#include "SFMLDrawable.h"
#include "SFMLRectangle.h"
#include "SFMLInput.h"
#include "projectile.h"
#include "GameState.h"
#include "MainMenu.h"
#include "EnemyPokemon.h"
#include "PokemonBar.h"
#include "SFML/Audio.hpp"
#include "GUI.h"

class Game
{
public:
	Game();
	~Game();

	// GameState is set to MainMenu
	GameState m_gameState{ GameState::MAIN_MENU };

	void run();

private:
	MainMenu m_menu;

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void loadTextures();
	void collisions();
	void processDamage();

	void initFonts();

	void initMusic();

	//Pokemon selection bar
	PokemonBar bar;

	//Player Pokemon
	SFMLDrawable playerSprite;
	SFMLInput playerInput;
	std::unique_ptr<Pokemon> player;

	//Enemy Pokemon
	EnemyPokemon enemyPokemon;

	//bullets
	SFMLDrawable bulletSprites[10];
	projectile bullets[10];
	int currentBullet = 0;
	sf::Clock cooldown;

	//bush
	SFMLDrawable bushShape;
	SFMLDrawable background;

	//Terrain
	sf::Sprite terrain;
	sf::Texture terrainTexture;

	//Damage Effect
	sf::RectangleShape damageEffect;
	float visability{ 0 };

	// Fonts
	sf::Font m_font;
	GUI gui;

	//music
	sf::SoundBuffer buffer;
	sf::Sound sound;

	//Misc
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

