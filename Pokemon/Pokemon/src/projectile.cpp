#include "projectile.h"


projectile::projectile()
{
	inilitalize();
}

void projectile::inilitalize()
{
	shape.setSize(sf::Vector2f(50, 50));
	shape.setPosition(sf::Vector2f{ -100, -100 });
	shape.setFillColor(sf::Color::Blue);
}

void projectile::draw(sf::RenderWindow& t_window)
{
	t_window.draw(sprite);
}

void projectile::debugDraw(sf::RenderWindow& t_window)
{
	t_window.draw(shape);
}

void projectile::changeType(int type)
{
	switch (type)
	{
	case 1:
		shape.setFillColor(sf::Color::Blue);
		break;
	case 2:
		shape.setFillColor(sf::Color::Green);
		break;
	case 3:
		shape.setFillColor(sf::Color::Black);
		break;
	case 4:
		shape.setFillColor(sf::Color::Red);
		break;
	case 5:
		shape.setFillColor(sf::Color::Magenta);
		break;
	case 6:
		shape.setFillColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}

void projectile::moveBullet()
{
	if (active)
	{
		float angle = thor::polarAngle(direction);


		position += direction * speed;
		shape.setPosition(position);
		shape.setRotation(angle - 90);
	}
}
