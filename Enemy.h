#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;


class Enemy
{
public:
	Sprite enemy_Sprite;
	Texture enemy_Texture;
	Enemy()
	{
		enemy_Texture.loadFromFile("IMG/enemyTexture.png");
		enemy_Sprite.setTexture(enemy_Texture);
		enemy_Sprite.setScale(1.5, 1.5);
	}
	void SetEnemyPosition(float a, float b)
	{
		enemy_Sprite.setPosition(a, b);
	}
};