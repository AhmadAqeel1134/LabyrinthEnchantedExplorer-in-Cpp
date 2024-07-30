#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Keys
{
public:
	sf::RectangleShape shape;

	Keys()
	{
		int keyDimension = 32;
		shape.setSize(sf::Vector2f(keyDimension,keyDimension));
		shape.setOutlineColor(sf::Color::Transparent);
		shape.setOutlineThickness(-1);
	}
};