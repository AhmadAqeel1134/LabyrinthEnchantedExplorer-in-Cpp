#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Exit
{
public:
	sf::RectangleShape shape;

	Exit()
	{
		int exitDimension = 32;
		shape.setSize(sf::Vector2f(exitDimension, exitDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};