#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Maps
{
public:
	sf::RectangleShape shape;

	Maps()
	{
		int mapsDimension = 32;
		shape.setSize(sf::Vector2f(mapsDimension, mapsDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};