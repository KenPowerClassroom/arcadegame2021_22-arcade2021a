#pragma once
#include <SFML/Graphics.hpp>

class GUI
{
public:
	GUI();
	void update();
	void draw(sf::RenderWindow& window);
	void increaseScore(int _score) { score += _score; scoreText.setString("Score: " + score); }

private:
	sf::Font font;
	sf::Text scoreText;
	int score = 0;
};

