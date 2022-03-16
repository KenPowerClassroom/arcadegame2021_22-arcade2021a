#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Gizmos.h"
#include <SFML/Graphics.hpp>
#include "Types.h"


class projectile
{
public:
	projectile();
	void draw(sf::RenderWindow& m_window);
	void update();
	void init();

	void setPos(Gizmos::Vector2 t_position) { position = Gizmos::Vector2f((float)t_position.x, (float)t_position.y); }
	void changeType(int t_type);
	void moveBullet();
	void calculateDirection(Gizmos::Vector2 t_mousePos);
	sf::Sprite getSprite() { return bulletSprite; }
	void setActive(bool t_active) { active = t_active; }
	bool getActive() { return active; }
	Type getType() { return m_type; }

	bool active; //Projectile active

private:

	Gizmos::Vector2f position{ 0,0 };
	Gizmos::Vector2f direction{ 0,0 };
	float speed{ 1.1f };
	Type m_type{ Type::Fire };

	sf::Sprite bulletSprite;
	sf::Texture bulletTexture;

};

#endif