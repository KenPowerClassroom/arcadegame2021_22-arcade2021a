#include "SFMLDrawable.h"

SFMLDrawable::SFMLDrawable()
{
}

SFMLDrawable::SFMLDrawable(const char* path)
{
	tex.loadFromFile(path);
	body.setTexture(tex);
}

void SFMLDrawable::Draw(Gizmos::Vector2 t_position, sf::RenderWindow& t_window)
{
	//body.setPosition(t_position);
	shape.setPosition(t_position.x, t_position.y);
	//window.draw(body);
	t_window.draw(shape);
}

void SFMLDrawable::setPath(const char* path)
{
	tex.loadFromFile(path);
}

void SFMLDrawable::setDrawableSize(float t_width, float t_height)
{
	shape.setSize(sf::Vector2f(t_width, t_height));
}

void SFMLDrawable::setDrawableColor(sf::Color t_color)
{
	shape.setFillColor(t_color);
}

void SFMLDrawable::setDrawableRotation(float t_rotation)
{
	shape.setRotation(t_rotation);
}
