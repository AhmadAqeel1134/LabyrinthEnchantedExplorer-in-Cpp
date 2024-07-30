#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Floor
{
public:
	sf::RectangleShape shape;

	Floor()
	{
		int tileDimension = 32;
		shape.setSize(sf::Vector2f(tileDimension, tileDimension));
	}
};