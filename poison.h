#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Poison
{
public:
	sf::RectangleShape shape;

	Poison()
	{
		int poisonDimension = 32;
		shape.setSize(sf::Vector2f(poisonDimension, poisonDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};