#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Sword
{
public:
	sf::RectangleShape shape;

	Sword()
	{
		int swordDimension = 32;
		shape.setSize(sf::Vector2f(swordDimension, swordDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};