#pragma once
#include "Input.h"
#include "Gizmos.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class SFMLInput : public Input
{
	sf::RenderWindow& window;
public:
	SFMLInput(sf::RenderWindow& _window) : window{_window} {}
	bool KeyPressed(Key k);
	Gizmos::Vector2 GetMousePos();
};

