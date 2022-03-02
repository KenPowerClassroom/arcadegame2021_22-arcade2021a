#include "MainMenu.h"

MainMenu::MainMenu(sf::Font& hudFont)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(GameState const& m_gameState)
{
    switch (m_gameState)
    {
    case GameState::GAME_PLAY:
        break;
    case GameState::GAME_WIN:
        break;
    case GameState::GAME_LOSE:
        break;
    case GameState::MAIN_MENU:
        
        break;
    default:
        break;
    }
}

void MainMenu::render(sf::RenderWindow& m_window)
{
}
