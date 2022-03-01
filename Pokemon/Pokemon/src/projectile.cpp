#include "projectile.h"


projectile::projectile()
{
	inilitalize();
}

void projectile::inilitalize()
{
	attack.setDrawableSize(50, 50);
	attack.setDrawableColor(sf::Color::Red);
}

void projectile::draw(sf::RenderWindow& t_window)
{
	if (active)
	{
		attack.Draw(position, t_window);
	}
}

void projectile::changeType(int type)
{
	switch (type)
	{
	case 1:
		attack.setDrawableColor(sf::Color::Red);
		break;
	case 2:
		attack.setDrawableColor(sf::Color::Green);
		break;
	case 3:
		attack.setDrawableColor(sf::Color::Blue);
		break;
	case 4:
		attack.setDrawableColor(sf::Color::Black);
		break;
	case 5:
		attack.setDrawableColor(sf::Color::Magenta);
		break;
	case 6:
		attack.setDrawableColor(sf::Color::Yellow);
		break;
	default:
		break;
	}
}

void projectile::setDirection(Vector2 t_mousePosition)
{
	if (t_mousePosition.x != 0 &&
		t_mousePosition.y != 0)
	{
		direction = t_mousePosition - position;
		float vectorLength = sqrt(direction.x * direction.x + direction.y * direction.y);
		sf::Vector2f temp = { (float)direction.x, (float)direction.y };
		temp = temp / vectorLength;
		direction.x = temp.x;
		direction.y = temp.y;

		setRotation();
	}
}

void projectile::setRotation()
{
	sf::Vector2f temp = { (float)direction.x, (float)direction.y };
	angle = thor::polarAngle(temp);
}

void projectile::moveBullet()
{
	if (active)
	{
		Vector2 temp = direction;
		position = position + (direction * speed);
		direction = temp;
		attack.setDrawableRotation(angle - 90);
	}
}

void projectile::shoot(Vector2 t_mousePosition)
{
	if (active == false)
	{
		setPos(attackStartPos);
		setDirection(t_mousePosition);
		active = true;
	}
}

void projectile::boundsCheck()
{
	if (active)
	{
		if (position.x > 1200 ||
			position.x < 0 ||
			position.y > 900 ||
			position.y < 0)
		{
			active = false;
		}
	}
}
