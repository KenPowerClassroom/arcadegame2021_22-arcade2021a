#include "projectile.h"
#include <cmath>
#include <iostream>

projectile::projectile(Drawable& _bulletSprite) :
	bulletSprite{ _bulletSprite }, active{ false }
{
}

void projectile::draw()
{
	if (active) bulletSprite.Draw(position.x, position.y);
}

void projectile::update()
{
	if (active) moveBullet();
}

void projectile::changeType(int type)
{
	switch (type)
	{
	case 0:
		bulletSprite.ChangeTexture("resources/images/electric.png");
		break;
	case 1:
		bulletSprite.ChangeTexture("resources/images/fire.png");
		break;
	case 2:
		bulletSprite.ChangeTexture("resources/images/water.png");
		break;
	}
}

void projectile::moveBullet()
{
	position = position + (direction * speed);
}

void projectile::calculateDirection(Gizmos::Vector2 t_mousePos)
{
	Gizmos::Vector2f mpos = Gizmos::Vector2f((float)t_mousePos.x, (float)t_mousePos.y);
	direction = mpos - position;
	float vectorLength = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction = direction / vectorLength;
	
	std::cout << direction.x << ", " << direction.y << std::endl;
}
