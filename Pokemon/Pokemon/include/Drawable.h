#pragma once

#include "Gizmos.h"
#include <SFML/Graphics.hpp>

class Drawable {
public:
	virtual void Draw(Gizmos::Vector2 t_position, sf::RenderWindow& t_window) = 0;
};