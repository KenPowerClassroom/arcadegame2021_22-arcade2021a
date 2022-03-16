#include "projectile.h"
#include <cmath>
#include <iostream>

projectile::projectile() :
 active{ false }
{
	init();
}

void projectile::draw(sf::RenderWindow& m_window)
{
	if (active) m_window.draw(bulletSprite);
}

void projectile::update()
{
	if (active) moveBullet();
}

void projectile::init()
{
	bulletTexture.loadFromFile("resources/images/electric.png");
	bulletSprite.setTexture(bulletTexture);
}

void projectile::changeType(int type)
{
	switch (type)
	{
	case 0:
		bulletTexture.loadFromFile("resources/images/electric.png");
		m_type = Type::Electric;
		break;
	case 1:
		bulletTexture.loadFromFile("resources/images/fire.png");
		m_type = Type::Fire;
		break;
	case 2:
		bulletTexture.loadFromFile("resources/images/water.png");
		m_type = Type::Water;
		break;
	}
}

void projectile::moveBullet()
{
	if (active)
	{
		position = position + (direction * speed);
		bulletSprite.setPosition(position.x, position.y);
	}
}

void projectile::calculateDirection(Gizmos::Vector2 t_mousePos)
{
	Gizmos::Vector2f mpos = Gizmos::Vector2f((float)t_mousePos.x, (float)t_mousePos.y);
	direction = mpos - position;
	float vectorLength = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction = direction / vectorLength;
	
	std::cout << direction.x << ", " << direction.y << std::endl;
}
