#pragma once
#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Shovel
{
public:
	sf::RectangleShape shape;

	Shovel()
	{
		int shovelDimension = 32;
		shape.setSize(sf::Vector2f(shovelDimension, shovelDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};