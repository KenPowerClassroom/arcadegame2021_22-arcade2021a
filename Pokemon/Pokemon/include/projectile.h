#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include "Thor/Vectors.hpp"

class projectile
{
public:
	projectile();
	void inilitalize();
	void draw(sf::RenderWindow& t_window);
	void debugDraw(sf::RenderWindow& t_window);

	void setXPos(float t_x) { sprite.setPosition(t_x, sprite.getPosition().y); }
	void setYPos(float t_y) { sprite.setPosition(sprite.getPosition().x, t_y); }
	void setPos(sf::Vector2f t_position) { position = t_position; }
	void setDirection(sf::Vector2f t_direction) { direction = t_direction; }
	void changeType(int t_type);
	void moveBullet();

	sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::Sprite& getSprite() { return sprite; }

private:

	bool active; //Projectile active
	sf::Vector2f position{ 1,1 };
	sf::Vector2f direction{ 1,1 };
	float speed{ 5 };


	sf::Sprite sprite;
	//sf::Texture& texture;

	//DEBUG
	sf::RectangleShape shape;

};

#endif