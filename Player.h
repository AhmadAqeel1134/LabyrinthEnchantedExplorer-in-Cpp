
#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <time.h>
using namespace sf;
class Player
{
public:
	sf::Sprite sprite;
	sf::Texture texture;
	Player()
	{
		sprite.setScale(2,2);
		texture.loadFromFile("IMG/playerTexture.png");
		sprite.setTexture(texture);
	}
};