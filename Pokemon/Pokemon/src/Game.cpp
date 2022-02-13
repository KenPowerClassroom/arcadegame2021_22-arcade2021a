#include "Game.h"

/// <summary>
/// default constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1200U, 900U, 32U }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
	loadTextures(); // load background
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
		if (sf::Event::KeyReleased == newEvent.type)
		{
			processKeyReleases(newEvent);
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
	if (sf::Keyboard::Space == t_event.key.code)
	{
		if (timer(0.5, attackTimer) == true)
		{
			playerAttack[currentAttack].shoot(mousePosition);
			playerAttack[currentAttack].changeType(currentPokemon);
			currentAttack++;
			if (currentAttack > 9)
			{
				currentAttack = 0;
			}
		}
	}
	if (sf::Keyboard::Q == t_event.key.code)
	{
		currentPokemon = 1;
	}
	if (sf::Keyboard::W == t_event.key.code)
	{
		currentPokemon = 2;
	}
	if (sf::Keyboard::E == t_event.key.code)
	{
		currentPokemon = 3;
	}
	if (sf::Keyboard::A == t_event.key.code)
	{
		currentPokemon = 4;
	}
	if (sf::Keyboard::S == t_event.key.code)
	{
		currentPokemon = 5;
	}
	if (sf::Keyboard::D == t_event.key.code)
	{
		currentPokemon = 6;
	}
}

/// <summary>
/// Processes the keys released on the keyboard
/// </summary>
/// <param name="t_event">the key released</param>
void Game::processKeyReleases(sf::Event t_event)
{
	if (sf::Event::KeyReleased == t_event.type)
	{
		if (sf::Keyboard::Q == t_event.key.code ||
			sf::Keyboard::W == t_event.key.code ||
			sf::Keyboard::E == t_event.key.code ||
			sf::Keyboard::A == t_event.key.code ||
			sf::Keyboard::S == t_event.key.code ||
			sf::Keyboard::D == t_event.key.code
			)
		{
			playerPokemon.changeType(currentPokemon);
			pokemonBar.selectPokemon(currentPokemon);
		}
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
	mousePosition = getMousePosition();
	for (size_t i = 0; i < MAX_ATTACKS; i++)
	{
		if (playerAttack[i].getActive())
		{
			playerAttack[i].moveBullet();
		}
	}
	collisions();
	enemyPokemon.update();
}

/// <summary>
/// draws the sprites and displays the window
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);

	m_window.draw(bushShape);
	playerPokemon.draw(m_window);
	enemyPokemon.draw(m_window);
	for (size_t i = 0; i < MAX_ATTACKS; i++)
	{
		playerAttack[i].draw(m_window);
	}
	pokemonBar.draw(m_window);

	m_window.display();
}

bool Game::timer(float t_desiredTime, sf::Clock t_timer)
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

/// <summary>
/// sets the textures and sprites
/// </summary>
void Game::loadTextures()
{
	bushShape.setSize(sf::Vector2f(600, 300));
	bushShape.setPosition(sf::Vector2f{ 500, 100 });
	bushShape.setFillColor(sf::Color::Green);
}

void Game::collisions()
{
	for (size_t i = 0; i < MAX_ATTACKS; i++)
	{
		playerAttack[i].boundsCheck();
		if (enemyPokemon.getBounds().intersects(playerAttack[i].getBounds()) &&
			playerAttack[i].getActive())
		{
			playerAttack[i].activeOff();
			enemyPokemon.pokemonHit(playerPokemon.getType());
		}
	}
}

/// <summary>
/// Finds the mouse position
/// </summary>
/// <returns>mouse coordinates</returns>
Vector2 Game::getMousePosition()
{
	mousePosition.x = (float)sf::Mouse::getPosition(m_window).x;
	mousePosition.y = (float)sf::Mouse::getPosition(m_window).y;

	return mousePosition;
}

