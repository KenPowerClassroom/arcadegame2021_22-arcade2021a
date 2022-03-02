#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Gizmos.h"
#include "Drawable.h"

class projectile
{
public:
	projectile(Drawable& _bulletSprite);
	void draw();
	void update();

	void setPos(Gizmos::Vector2 t_position) { position = Gizmos::Vector2f((float)t_position.x, (float)t_position.y); }
	void changeType(int t_type);
	void moveBullet();
	void calculateDirection(Gizmos::Vector2 t_mousePos);

	bool active; //Projectile active

private:

	Gizmos::Vector2f position{ 0,0 };
	Gizmos::Vector2f direction{ 0,0 };
	float speed{ 1.1f };

	Drawable& bulletSprite;

};

#endif