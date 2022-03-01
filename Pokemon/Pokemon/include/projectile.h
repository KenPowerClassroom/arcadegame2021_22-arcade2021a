#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "SFMLDrawable.h"
#include "Gizmos.h"
#include "Thor/Vectors.hpp"

using namespace Gizmos;

class projectile
{
public:
	projectile();
	void inilitalize();
	void draw(sf::RenderWindow& t_window);
	void changeType(int t_type);
	void moveBullet();
	void shoot(Vector2 t_mousePosition);
	void boundsCheck();
	void activeOff() { active = false; }

	//Setters
	void setPos(Vector2 t_position) { position = t_position; }
	void setDirection(Vector2 t_mousePosition);
	void setRotation();
	//Getters
	sf::FloatRect getBounds() { return attack.getBounds(); }
	bool getActive() { return active; }

private:

	bool active{ false }; //Projectile active
	Vector2 position{ -100, -100 };
	Vector2 attackStartPos{ 250, 650 };
	Vector2 direction{ -1, -1 };
	float speed{ 10 };
	float angle;


	SFMLDrawable attack;

};

#endif