#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Telephone
{
public:
	sf::RectangleShape shape;

	Telephone()
	{
		int telephoneDimension = 32;
		shape.setSize(sf::Vector2f(telephoneDimension, telephoneDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};