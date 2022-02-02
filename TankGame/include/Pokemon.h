#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <SFML/Graphics.hpp>

class Pokemon
{
public:
	Pokemon();
	void inilitalize();
	void draw(sf::RenderWindow& t_window);
	void debugDraw(sf::RenderWindow& t_window);

	void setXPos(float t_x) { sprite.setPosition(t_x, sprite.getPosition().y); }
	void setYPos(float t_y) { sprite.setPosition(sprite.getPosition().x, t_y); }

	sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::Sprite& getSprite() { return sprite; }

private:
	static int pokemonCreated;

	sf::Sprite sprite;
	//sf::Texture& texture;

	//DEBUG

	sf::RectangleShape shape;
};

#endif