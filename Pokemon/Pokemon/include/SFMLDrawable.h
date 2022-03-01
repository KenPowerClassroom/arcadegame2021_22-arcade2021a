#pragma once
#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include "Gizmos.h"

class SFMLDrawable : public Drawable 
{
public:
	SFMLDrawable();
	SFMLDrawable(const char* path);
	void Draw(Gizmos::Vector2 t_position, sf::RenderWindow& t_window);

	//Setters
	void setPath(const char* path);
	void setDrawableSize(float t_width, float t_height);
	void setDrawableColor(sf::Color t_color);
	void setDrawableRotation(float t_rotation);
	//Getters
	sf::FloatRect getBounds() { return shape.getGlobalBounds(); }

private:
	sf::Sprite body;
	sf::RectangleShape shape;
	sf::Texture tex;
};