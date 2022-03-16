#include "GUI.h"

GUI::GUI()
{
	font.loadFromFile("resources/fonts/Gameplay.ttf");
	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setString("Score: 0");
	scoreText.setPosition(10, 20);
}

void GUI::update()
{
}

void GUI::draw(sf::RenderWindow& window)
{
	window.draw(scoreText);
}
