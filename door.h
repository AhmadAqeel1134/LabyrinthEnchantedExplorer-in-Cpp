#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Door
{
public:
	sf::RectangleShape shape;

	Door()
	{
		int doorDimension = 35;
		shape.setSize(sf::Vector2f(doorDimension, doorDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};