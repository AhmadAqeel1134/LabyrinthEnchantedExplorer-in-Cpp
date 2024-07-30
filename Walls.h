#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Wall
{

public:
	sf::RectangleShape shape;

	Wall()
	{
		int tileDimension = 32;
		shape.setSize(sf::Vector2f(tileDimension, tileDimension));
		shape.setOutlineColor(sf::Color::Black);
		shape.setOutlineThickness(-1);
	}

};