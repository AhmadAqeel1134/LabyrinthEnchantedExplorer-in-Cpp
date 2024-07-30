#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class POINTS
{
public:
	
	sf::RectangleShape shape;

	POINTS()
	{
		int tileDimension = 32;
		shape.setSize(sf::Vector2f(tileDimension, tileDimension));
		shape.setOutlineColor(sf::Color::Magenta);
		shape.setOutlineThickness(-1);
	}
	void SetPoints(int xAxis, int yAxis)
	{
		shape.setPosition(xAxis, yAxis);
	}

};