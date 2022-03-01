#include "Game.h"

/// <summary>
/// default constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1200U, 900U, 32U }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	playerSprite{ "resources/images/pikachu.png",m_window },
	playerInput{ m_window },
	player{ std::make_unique<Pokemon>(playerSprite, playerInput) }
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
		player.get()->pollInput();
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
}

/// <summary>
/// draws the sprites and displays the window
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);


	//DEBUG
	player->draw();
	//attackProjectile.debugDraw(m_window);
	m_window.draw(bushShape);

	m_window.display();
}

/// <summary>
/// loads the background for the game
/// </summary>
void Game::loadTextures()
{
	////Sprite Sheet Loading
	//if (!textureSheet.loadFromFile("spritesheet.png"))
	//{
	//	std::cout << "problem loading sheet" << std::endl;
	//}

	////Font Loading
	//if (!arial.loadFromFile("ariblk.ttf"))
	//{
	//	std::cout << "problem loading arial black font" << std::endl;
	//}
	//scoreText.setFont(arial);
	//scoreText.setPosition(800, 0);
	//scoreText.setCharacterSize(20U);
	//scoreText.setFillColor(sf::Color(88, 88, 88));
	//scoreText.setString("00000");


	bushShape.setSize(sf::Vector2f(600, 300));
	bushShape.setPosition(sf::Vector2f{ 500, 100 });
	bushShape.setFillColor(sf::Color::Green);

}

void Game::collisions()
{

}


//void Game::shootProjectile()
//{
	//mouseDirection = playerPokemon[currentPokemon].getPosition() - mousePosition;
	//mouseDirection = thor::unitVector(mouseDirection);

	//attackProjectile.setPos(playerPokemon[currentPokemon].getPosition());
	//attackProjectile.setDirection(mouseDirection);
//}
