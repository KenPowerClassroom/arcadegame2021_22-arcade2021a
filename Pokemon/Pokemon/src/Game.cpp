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
	selectedPokemon{ SFMLRectangle(25,25,m_window), SFMLRectangle(25,25,m_window), SFMLRectangle(25,25,m_window) },
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
	if (playerInput.KeyPressed(playerInput.Num1))
	{
		player.get()->setPokemon(0);
		selectedPokemon[0].SetColour(sf::Color::Yellow);
		selectedPokemon[1].SetColour(sf::Color::Black);
		selectedPokemon[2].SetColour(sf::Color::Black);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(0);
		}
	}
	if (playerInput.KeyPressed(playerInput.Num2))
	{
		player.get()->setPokemon(1);
		selectedPokemon[0].SetColour(sf::Color::Black);
		selectedPokemon[1].SetColour(sf::Color::Red);
		selectedPokemon[2].SetColour(sf::Color::Black);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].changeType(1);
		}
	}
	if (playerInput.KeyPressed(playerInput.Num3))
	{
		player.get()->setPokemon(2);
		selectedPokemon[0].SetColour(sf::Color::Black);
		selectedPokemon[1].SetColour(sf::Color::Black);
		selectedPokemon[2].SetColour(sf::Color::Blue);
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
<<<<<<< HEAD
		enemyPokemon.update();
=======
		enemies.update();
>>>>>>> 0f068a7fecd225717b98f34b1efe57dab7fe42b5
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
		player->draw();
		//attackProjectile.debugDraw(m_window);
		bushShape.Draw(500, 100);
		enemyPokemon.draw(m_window);
		for (int i = 0; i < 10; i++)
		{
			bullets[i].draw(m_window);
		}
		for (int i = 0; i < 3; i++)
		{
			selectedPokemon[i].Draw(i * 50 + 50, 591);
		}
		enemies.draw(m_window);
		gui.draw(m_window);
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
	for (int i = 0; i < 3; i++)
	{
		selectedPokemon[i].SetColour(sf::Color::Black);
	}
	selectedPokemon[0].SetColour(sf::Color::Yellow);
}

void Game::collisions()
{

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
