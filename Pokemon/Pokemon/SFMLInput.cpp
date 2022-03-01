#include "SFMLInput.h"

bool SFMLInput::KeyPressed(Key k)
{
    sf::Keyboard::Key _k = static_cast<sf::Keyboard::Key>(k);
    return sf::Keyboard::isKeyPressed(_k);
}

Gizmos::Vector2 SFMLInput::GetMousePos()
{
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    return Gizmos::Vector2(pos.x, pos.y);
}
