#include "MainMenu.h"

MainMenu::MainMenu(sf::Font& hudFont)
{
    initSprites();
    initShapes();
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(GameState const& m_gameState)
{

}

/// <summary>
/// draws objects on window screen
/// </summary>
/// <param name="m_window"></param>
void MainMenu::render(sf::RenderWindow& m_window)
{
    m_window.clear(sf::Color::Black);
    
    m_window.draw(m_outlineSprite);
    //m_window.draw(m_startRect);
    //m_window.draw(m_optionsRect);
    //m_window.draw(m_exitRect);
}

/// <summary>
/// initialize Sprites
/// </summary>
void MainMenu::initSprites()
{
    if (!m_outlineTexture.loadFromFile("./resources//images//UI//GUI_1.png"))
    {
        std::cout << "Error - Loading Image\n";
    }
    m_outlineSprite.setTexture(m_outlineTexture);
    m_outlineSprite.setPosition(600, 450);
    m_outlineSprite.setScale(5, 5);
    m_outlineSprite.setOrigin(22, 33);
}

/// <summary>
/// initializes shapes
/// </summary>
void MainMenu::initShapes()
{
    m_startRect.setSize(sf::Vector2f(140, 60));
    m_startRect.setPosition(600, 350);
    m_startRect.setOrigin(70, 10);
    m_startRect.setFillColor(sf::Color::Red);

    m_optionsRect.setSize(sf::Vector2f(140, 60));
    m_optionsRect.setPosition(600, 430);
    m_optionsRect.setOrigin(70, 10);
    m_optionsRect.setFillColor(sf::Color::Blue);

    m_exitRect.setSize(sf::Vector2f(140, 60));
    m_exitRect.setPosition(600, 510);
    m_exitRect.setOrigin(70, 10);
    m_exitRect.setFillColor(sf::Color::Yellow);
}

/// <summary>
/// Checks Mouse input, changes GameState 
/// </summary>
/// <param name="m_event"> takes mouse Event </param>
/// <param name="m_gameState"> changes Gamestate </param>
void MainMenu::mouseInput(sf::Event m_event, GameState & m_gameState)
{
    if (m_event.type == sf::Event::MouseButtonPressed)
    {
        if (m_event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "the left button was pressed" << std::endl;
            std::cout << "mouse x: " << m_event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << m_event.mouseButton.y << std::endl;
            std::cout << "\n";
            if (m_event.mouseButton.x > 530 && m_event.mouseButton.x < 670 &&
                m_event.mouseButton.y > 340 && m_event.mouseButton.y < 400)
            {
                m_gameState = GameState::GAME_PLAY;
            }
            if (m_event.mouseButton.x > 530 && m_event.mouseButton.x < 670 &&
                m_event.mouseButton.y > 420 && m_event.mouseButton.y < 480)
            {
                //m_gameState = GameState::OPTIONS;
            }
            if (m_event.mouseButton.x > 530 && m_event.mouseButton.x < 670 &&
                m_event.mouseButton.y > 500 && m_event.mouseButton.y < 560)
            {
                m_gameState = GameState::EXIT;
            }
        }
    }
}
