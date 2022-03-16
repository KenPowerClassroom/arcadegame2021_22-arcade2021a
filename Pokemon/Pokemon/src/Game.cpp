#include "Game.h"

/// <summary>
/// default constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1200U, 900U, 32U }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	playerSprite{ "resources/images/pikachu.png",m_window },
	playerInput{ m_window },
	player{ std::make_unique<Pokemon>(playerSprite, playerInput) },
	bushShape{ "./resources/images/world/grassSideView.png", m_window },
	background{ "./resources/images/world/background.png", m_window },
	bulletSprites{ SFMLDrawable("resources/images/electric.png",m_window), SFMLDrawable("resources/images/electric.png",m_window),
	SFMLDrawable("resources/images/electric.png",m_window), SFMLDrawable("resources/images/electric.png",m_window),
	SFMLDrawable("resources/images/electric.png",m_window), SFMLDrawable("resources/images/electric.png",m_window),
	SFMLDrawable("resources/images/electric.png",m_window), SFMLDrawable("resources/images/electric.png",m_window),
	SFMLDrawable("resources/images/electric.png",m_window), SFMLDrawable("resources/images/electric.png",m_window) },
	m_menu(m_font)
{
	loadTextures(); // load background
	initFonts();
	initMusic();
}

/// <summary>
/// default destructor
/// </summary>
Game::~Game()
{
}

/// <summary>
/// main game loop
/// updates 60 times per second
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	srand(time(NULL));  // Initialize random number generator

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handles events and inputs fron the user
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		player.get()->pollInput();
		switch (m_gameState)
		{
		case GameState::MAIN_MENU:
			m_menu.mouseInput(newEvent, m_gameState);
			break;
		default:
			break;
		}
	}
}


/// <summary>
/// handles the key presses by the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
	if (playerInput.KeyPressed(playerInput.Q))
	{
		player.get()->setPokemon(0);
		bar.selectPokemon(1);
		for (int i = 0; i < 10; i++)
		{
			if (bullets[i].active == false)
			{
				bullets[i].changeType(0);
			}
		}
	}
	if (playerInput.KeyPressed(playerInput.W))
	{
		player.get()->setPokemon(1);
		bar.selectPokemon(2);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(1);
		}
	}
	if (playerInput.KeyPressed(playerInput.E))
	{
		player.get()->setPokemon(2);
		bar.selectPokemon(3);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(2);
		}
	}
	if (playerInput.KeyPressed(playerInput.A))
	{
		player.get()->setPokemon(3);
		bar.selectPokemon(4);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(2);
		}
	}
	if (playerInput.KeyPressed(playerInput.S))
	{
		player.get()->setPokemon(4);
		bar.selectPokemon(5);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(2);
		}
	}
	if (playerInput.KeyPressed(playerInput.D))
	{
		player.get()->setPokemon(5);
		bar.selectPokemon(6);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(2);
		}
	}
	if (playerInput.KeyPressed(playerInput.Space) && cooldown.getElapsedTime().asSeconds() > 0.5f)
	{
		bullets[currentBullet].setPos(Gizmos::Vector2(200, 700));
		bullets[currentBullet].active = true;
		bullets[currentBullet].calculateDirection(playerInput.GetMousePos());
		currentBullet++;
		if (currentBullet == 10)
		{
			currentBullet = 0;
		}
		cooldown.restart();
	}
	if (playerInput.KeyPressed(playerInput.S))
	{
		enemyPokemon.Spawn();
	}
}


/// <summary>
/// Update the game
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	m_menu.update(m_gameState);
	switch (m_gameState)
	{
	case GameState::GAME_PLAY:
		for (int i = 0; i < 10; i++)
		{
			bullets[i].update();
			enemyPokemon.checkCollisions(bullets[i]);
		}
		enemyPokemon.update();
		processDamage();
		break;
	case GameState::GAME_WIN:
		break;
	case GameState::GAME_LOSE:
		break;
	case GameState::EXIT:
		m_exitGame = true;
	default:
		break;
	}
}

/// <summary>
/// draws the sprites and displays the window
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	background.Draw(0,0);

	switch (m_gameState)
	{
	case GameState::GAME_PLAY:
		m_window.draw(terrain);
		player->draw(m_window);
		//attackProjectile.debugDraw(m_window);
		bushShape.Draw(500, 100);
		enemyPokemon.draw(m_window);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].draw(m_window);
		}
		bar.draw(m_window);
		gui.draw(m_window);
		m_window.draw(damageEffect);
		break;
	case GameState::MAIN_MENU:
		m_menu.render(m_window);
		break;
	default:
		break;
	}
	m_window.display();
}

/// <summary>
/// loads the background for the game
/// </summary>
void Game::loadTextures()
{
	if (!terrainTexture.loadFromFile("./resources/images/terrain.png"))
	{
		std::cout << "Error loading terrain image\n";
	}
	terrain.setTexture(terrainTexture);
	terrain.setTextureRect(sf::IntRect{ 0,0,191,28 });
	terrain.setPosition(0,820);
	terrain.setScale(3,3);

	damageEffect.setSize(sf::Vector2f{ 1200,900 });
}

void Game::collisions()
{

}

void Game::processDamage()
{
	if (enemyPokemon.playerRecieveDamage())
	{
		visability = 255;
	}
	if (visability > 1)
	{
		int incrament = 3;
		visability -= incrament;
	}
	damageEffect.setFillColor(sf::Color::Color(255, 0, 0, visability));
}

void Game::initFonts()
{
	if (!m_font.loadFromFile("./resources/fonts/ariblk.ttf"))
	{
		std::cout << "Error loading Font\n";
	}
}

void Game::initMusic()
{
	if (!buffer.loadFromFile("./resources/music/PokemonCentreNight.wav"))
	{
		std::cout << "Error loading music" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.play();
	sound.setLoop(true);
	sound.setVolume(1);
}
