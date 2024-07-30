#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cstdlib>
#include<ctime>
#include <iostream>
#include <time.h>
#include <sstream>
#include "Walls.h"
#include "Player.h"
#include "Enemy.h"
#include "Points.h"
#include "Floor.h"
#include"keys.h"
#include"sword.h"
#include"Shovel.h"
#include"Maps.h"
#include"poison.h"
#include"Telephone.h"
#include"exit.h"
#include"door.h"
#include"AVL.h"

using namespace std;
using namespace sf;
int** generateRandom(int mazenum)
{
	int** mazeData = new int* [20];
	for (int i = 0; i < 20; i++)
	{
		mazeData[i] = new int[20];
	}

	
	if (mazenum == 0)
	{
		int m[20][20] = {
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 0, 0, 1, 1, 1, 0, 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, -1, 1},
	{1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, -1, 0, 1, 1, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 8, 0, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, -1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 1, 1, 1, 0, 1, 0, 1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 5, 0, 1},
	{1, 0, 1, 0, 1, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 0, 3, -1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 0, 0, 0, 0, 1, 1, 1, -1, 1},
	{1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, -1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
	{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1}
		};


		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				mazeData[i][j] = m[i][j];
			}
		}

	}
	else if (mazenum == 1)	//transpose of 0
	{
		int m[20][20] = {
		{ 1, 0,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
		{ 1, 0, 1, 1, 0, 0, 0, 1, -1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, },
		{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 5, 0, 1, },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, -1, 0, 1, },
		{ 1, 1, 0, 1, 0, 0, 0, 0, 1, -1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, },
		{ 1, 1, 0, 1, 1, 1, 1, 6, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, },
		{ 1, 0, -1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 1, },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, -1, 0, 1, },
		{ 1, 0, 0, 0, 0, 0, 1, -1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, },
		{ 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, },
		{ 1, 1, 0, -1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, },
		{ 1, 0, 0, 8, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, },
		{ 1, 0, 1, 0, 0, 0, 1, -1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, },
		{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 3, 1, },
		{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, -1, 1, 0, 4, 1, },
		{ 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, -1, 0, 1, },
		{ 1, 0, 1, 1, 1, 1, 7, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, },
		{ 1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 9, },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				mazeData[i][j] = m[i][j];
			}
		}
	}
	else if (mazenum == 2)	//rows interchange of 0
	{
		int m[20][20] = {
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, },
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 1, },
			{1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, },
			{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, },
			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, },
			{1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, },
			{1, 0, 0, 0, 6, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 1, },
			{1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, },
			{1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, },
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 5, 0, 0, 1, 1, 1, -1, 1, },
			{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 8, 3, 0, 1, },
			{1, -1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, },
			{1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, },
			{1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, },
			{1, 0, 1, 1, 1, 0, 1, -1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, },
			{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, },
			{1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 4, 1, },
			{1, 1, 1, 0, 1, 7, 0, 0, 1, -1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, },
			{0, 0, -1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, -1, 0, 0, 0, 0, 0, 1, },
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, } };
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				mazeData[i][j] = m[i][j];
			}
		}
	}
	else if (mazenum == 3)	//column interchange
	{
		int m[20][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, },
		{ 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 5, 1, 1, 1, 0, 1, 1, 1, },
		{ 1, 1, 1, 7, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, },
		{ 1, -1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, },
		{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 3, 0, 0, 1, },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
		{ 1, 0, 1, 0, -1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, -1, 0, 0, 1, },
		{ 1, 0, 0, 0, 1, 1, 0, 1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, },
		{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
		{ 1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 1, },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, },
		{ 1, -1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, -1, 1, 1, },
		{ 1, 0, 8, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 1, },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, },
		{ 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, } };
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				mazeData[i][j] = m[i][j];
			}
		}	
	}	
	return mazeData;
}	
class Game
{
	
    float mazeX;
    float mazeY;
    int tileDimension;
    int Enemy1Direction;
    int Enemy2Direction;
    int Enemy3Direction;
    int Enemy4Direction;
    int playerLives;
	int pointIndex;
    int score;
	int RandomMaze;

	bool hasTelephone;
	bool hasSword;
	bool hasKey;
	bool hasShovel;
	bool hasMap;
	bool hasPoison;

	AVLTree objAvl;
	Keys key;
	Sword sword;
	Maps maps;
    Wall wall;
    Floor floor;
	Shovel shovel;
	Poison poison;
	Telephone telephone;
	Door door;
	Exit exit;
    Player player;
    Enemy enemy1;
    Enemy enemy2;
    Enemy enemy3;
    Enemy enemy4;
	Font font1;
	POINTS points[11];
	Music m1;
	Music m2;
    sf::Font font;
    sf::Text lives;
    sf::Text scores;
    sf::Text endGame;
    sf::Texture wallTexture;
    sf::Texture floorTexture;
    sf::Texture bombTexture;
    sf::Texture explosionTexture;
    sf::Texture pointsTexture[11];
	sf::Texture keysTexture;
	sf::Texture swordsTexture;
	sf::Texture shovelTexture;
	sf::Texture mapsTexture;
	sf::Texture poisonTexture;
	sf::Texture telephoneTexture;
	sf::Texture doorTexture;
	sf::Texture exitTexture;
	
	SoundBuffer audio1, audio2;
	Sound sound1, sound2;

	
	
    bool bombSet;
    bool playerHit;
    bool winCondition;
    bool loseCondition;
	bool EnemyHitPlayer;
	bool isMouseOverInv;
    std::vector<sf::FloatRect> walls;
	
	int maze1[20][20];
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame;
	sf::Clock clock;
	sf::Clock fuse;
	sf::Clock explosionTime;
	sf::Clock invulnerabilityTimer;

public:
	Game()
	{
		m2.play();
		srand(time(0));  
		RandomMaze = rand()%4;  //generating a random maze
		cout << "Random Maze " << RandomMaze << endl;
		int** mazeData = generateRandom(RandomMaze);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				maze1[i][j] = mazeData[i][j];
			}
		}

        mazeX = 0;
        mazeY = 0;
        tileDimension = 16;
        Enemy1Direction = 1;
        Enemy2Direction = 0;
        Enemy3Direction = 1;
        Enemy4Direction = 0;
		pointIndex = 0;
        playerLives = 3;
        score = 0;
        bombSet = false;
        playerHit = false;
        winCondition = false;
        loseCondition = false;
		isMouseOverInv = false;

		hasTelephone = 0;
		hasPoison = 0;
		hasSword = 0;
		hasShovel = 0;
		hasMap = 0;
		hasKey = 0;

        lives.setScale(0.4, 0.4);
        lives.setFont(font);
        scores.setScale(0.4, 0.4);
        scores.setFont(font);
        endGame.setScale(1, 1);
        endGame.setFont(font);
       
		if (RandomMaze == 0)
		{
			player.sprite.setPosition((0 * wall.shape.getGlobalBounds().width), (1 * wall.shape.getGlobalBounds().height));
			enemy1.SetEnemyPosition(580, 300);
			enemy2.SetEnemyPosition(70, 550);
			enemy3.SetEnemyPosition(100, 290);
			enemy4.SetEnemyPosition(385, 40);
		}
		else if (RandomMaze == 1)
		{
			player.sprite.setPosition((1 * wall.shape.getGlobalBounds().width), (2 * wall.shape.getGlobalBounds().height));
			enemy1.SetEnemyPosition(580, 300);
			enemy2.SetEnemyPosition(50, 515);
			enemy3.SetEnemyPosition(355, 40);
			enemy4.SetEnemyPosition(700,700);
		}
		else if (RandomMaze == 2)
		{
			player.sprite.setPosition((1 * wall.shape.getGlobalBounds().width), (18* wall.shape.getGlobalBounds().height));
			enemy2.SetEnemyPosition(50,40);
			enemy4.SetEnemyPosition(50, 200);
			enemy1.SetEnemyPosition(580,580);
			enemy3.SetEnemyPosition(700, 700);
		}
		else
		{
			player.sprite.setPosition((2 * wall.shape.getGlobalBounds().width), (1 * wall.shape.getGlobalBounds().height));
			enemy2.SetEnemyPosition(540, 580);
			enemy4.SetEnemyPosition(380, 40);
			enemy3.SetEnemyPosition(520, 280);
			enemy1.SetEnemyPosition(100, 40);
		}
        font.loadFromFile("font/font.ttf");
        wallTexture.loadFromFile("IMG/wallTexture.png");
        floorTexture.loadFromFile("IMG/floorTexture.png");
		keysTexture.loadFromFile("IMG/keyTexture.png");
		swordsTexture.loadFromFile("IMG/swordTexture.png");
		shovelTexture.loadFromFile("IMG/shovelTexture.png");
		mapsTexture.loadFromFile("IMG/mapsTexture.png");
		poisonTexture.loadFromFile("IMG/poisonTexture.png");
		telephoneTexture.loadFromFile("IMG/telephoneTexture.png");
		doorTexture.loadFromFile("IMG/doorTexture.png");
		exitTexture.loadFromFile("IMG/exitTexture.png");
		m1.openFromFile("audio/MainMenu.ogg");
		m2.openFromFile("audio/mainMusic.ogg");

		audio1.loadFromFile("audio/button_sound_01.wav");
		audio2.loadFromFile("audio/button_sound_02.wav");
		sound1.setBuffer(audio1);
		sound2.setBuffer(audio2);

		for (int i = 0; i < 11; i++)
		{
			pointsTexture[i].loadFromFile("IMG/scorePoint.png");
		}

	
        sf::Time threeSeconds = sf::seconds(3);
        sf::Time explosionSec = sf::seconds(4);
        sf::Time invulnerabilityDuration = sf::seconds(1.5);
        sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
        sf::Time timeSinceLastUpdate = sf::Time::Zero;

        clock.restart();

    }

	void startGame()
	{
		m2.play();
		sf::RenderWindow window(sf::VideoMode(640, 640), "Labyrinth Enchanted Explorer");
	
		//here displaying items in inventory
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				mazeX = j * wall.shape.getGlobalBounds().width;
				mazeY = i * wall.shape.getGlobalBounds().height;
				if (maze1[i][j] == 2)
				{
					
					key.shape.setPosition(mazeX, mazeY);
					key.shape.setTexture(&keysTexture);
				}
				else if (maze1[i][j] == 3)
				{
					sword.shape.setPosition(mazeX, mazeY);
					sword.shape.setTexture(&swordsTexture);
				}
				else if (maze1[i][j] == 4)
				{
					shovel.shape.setPosition(mazeX, mazeY);
					shovel.shape.setTexture(&shovelTexture);
				}
				else if (maze1[i][j] == 5)
				{
					maps.shape.setPosition(mazeX, mazeY);
					maps.shape.setTexture(&mapsTexture);
				}
				else if (maze1[i][j] == 6)
				{
					poison.shape.setPosition(mazeX, mazeY);
					poison.shape.setTexture(&poisonTexture);
				}
				else if (maze1[i][j] == 7)
				{
					telephone.shape.setPosition(mazeX, mazeY);
					telephone.shape.setTexture(&telephoneTexture);
				}
				else if (maze1[i][j] == 8)
				{
					door.shape.setPosition(mazeX, mazeY);
					 door.shape.setTexture(&doorTexture);
				}
				else if (maze1[i][j] == 9)
				{
					exit.shape.setPosition(mazeX, mazeY);
					exit.shape.setTexture(&exitTexture);
				}
			}
		}
		
		while (window.isOpen())
		{
			

			if (winCondition == false && loseCondition == false)
			{
				std::stringstream scoreStream;
				scoreStream << "Score: " << score;
				std::string scoreString = scoreStream.str();
				scores.setString(scoreString);
				std::stringstream livesStream;
				livesStream << "Lives: " << playerLives;
				std::string livesString = livesStream.str();
				lives.setString(livesString);
				lives.setPosition(560, 0);

				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}

				// add to the time since last update and restart the clock
				timeSinceLastUpdate += clock.restart();

				


				if (timeSinceLastUpdate > timePerFrame)
				{

					// Win and Lose events
					window.clear();
					if (playerLives == 0)
					{
						loseCondition = true;
					}

					if (score == 11)
					{
						winCondition = true;
					}

					// Draw in Maze
					for (int row = 0; row < 20; row++)
					{
						for (int col = 0; col < 20; col++)
						{
							mazeX = col * wall.shape.getGlobalBounds().width;
							mazeY = row * wall.shape.getGlobalBounds().height;

							if (maze1[row][col] == 1)
							{
								walls.push_back(wall.shape.getGlobalBounds());
								wall.shape.setPosition(mazeX, mazeY);
								wall.shape.setTexture(&wallTexture);
								window.draw(wall.shape);
							}
							else
							{
								floor.shape.setPosition(mazeX, mazeY);
								floor.shape.setTexture(&floorTexture);
								window.draw(floor.shape);
							}
							
						}
					}

					

					// drawing the enemy
					window.draw(enemy1.enemy_Sprite);
					window.draw(enemy2.enemy_Sprite);
					window.draw(enemy3.enemy_Sprite);
					window.draw(enemy4.enemy_Sprite);
					//drawing the key
					window.draw(key.shape);
					//drawing the sword
					window.draw(sword.shape);
					//drawing the shovel
					window.draw(shovel.shape);
					//drawing the maps
					window.draw(maps.shape);
					//drawing the poison
					window.draw(poison.shape);
					//drawing the telephone
					window.draw(telephone.shape);
					//drawing the door
					window.draw(door.shape);
					//drawing the exit
					window.draw(exit.shape);
					// dealing with collision

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						player.sprite.move(-1, 0);
						if (hasKey == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(door.shape.getGlobalBounds()))
							{
								player.sprite.move(1, 0);
							}
						}
						if (hasShovel == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(exit.shape.getGlobalBounds()))
							{
								player.sprite.move(1, 0);
							}
						}

						for (int i = 0; i < 640; i++) // 211 walls in maze
						{
							// General Collision Detect for player collisions

							if (player.sprite.getGlobalBounds().intersects(walls[i]))
							{
								player.sprite.move(1, 0);
							}
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{

						player.sprite.move(1, 0);
						if (hasKey == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(door.shape.getGlobalBounds()))
							{
								player.sprite.move(-1, 0);
							}
						}
						if (hasShovel == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(exit.shape.getGlobalBounds()))
							{
								player.sprite.move(-11, 0);
							}
						}

						for (int i = 0; i < 640; i++)
						{
							// General Collision Detect for player collisions

							if (player.sprite.getGlobalBounds().intersects(walls[i]))
							{
								player.sprite.move(-1, 0);
							}
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						player.sprite.move(0, -1);
						if (hasKey == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(door.shape.getGlobalBounds()))
							{
								player.sprite.move(0, 1);
							}
						}
						if (hasShovel == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(exit.shape.getGlobalBounds()))
							{
								player.sprite.move(0, 1);
							}
						}
						for (int i = 0; i <640; i++)
						{
							// General Collision Detect for player collisions

							if (player.sprite.getGlobalBounds().intersects(walls[i]))
							{
								player.sprite.move(0, 1);
							}
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{

						player.sprite.move(0, 1);
						if (hasKey == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(door.shape.getGlobalBounds()))
							{
								player.sprite.move(0,-1);
							}
						}
						if (hasShovel == 0)
						{
							if (player.sprite.getGlobalBounds().intersects(exit.shape.getGlobalBounds()))
							{
								player.sprite.move(0, -1);
							}
						}
						for (int i = 0; i < 640; i++)
						{
							// General Collision Detect for player collisions

							if (player.sprite.getGlobalBounds().intersects(walls[i]))
							{
								player.sprite.move(0, -1);
							}
						}
					}
					//if I key is pressed a new window for inventory open




					Event InvEvent;
					while (window.pollEvent(InvEvent)) {
						if (InvEvent.type == Event::Closed) {
							window.close();
						}



						if (InvEvent.type == Event::KeyPressed && InvEvent.key.code == Keyboard::I) {
							m2.pause();
							m1.play();
							RenderWindow inventoryWindow(sf::VideoMode(550, 550), "Inventory");
						;

							while (inventoryWindow.isOpen())
							{
								Event inventoryEvent;
								while (inventoryWindow.pollEvent(inventoryEvent))
								{
									if (inventoryEvent.type == sf::Event::Closed)
									{
										inventoryWindow.close();
										
									}
								}
								inventoryWindow.clear(sf::Color::Black);
								Text headText("INVENTORY", font, 30);
								headText.setFillColor(Color::White);
								headText.setPosition(inventoryWindow.getSize().x / 2 - headText.getGlobalBounds().width / 2, 50);
								inventoryWindow.draw(headText);


								// Define inventory item texts
								sf::Text poisonText("poison", font, 24);
								sf::Text telephoneText("telephone", font, 24);
								sf::Text mapText("map", font, 24);
								sf::Text swordText("sword", font, 24);
								sf::Text keyText("key", font, 24);
								sf::Text shovelText("shovel", font, 24);

								// Set initial text colors
								poisonText.setFillColor(Color::Green);
								telephoneText.setFillColor(Color::Green);
								mapText.setFillColor(Color::Green);
								swordText.setFillColor(Color::Green);
								keyText.setFillColor(Color::Green);
								shovelText.setFillColor(Color::Green);


								poisonText.setPosition(inventoryWindow.getSize().x / 2 - poisonText.getGlobalBounds().width / 2, 150);
								swordText.setPosition(inventoryWindow.getSize().x / 2 - swordText.getGlobalBounds().width / 2, 190);

								telephoneText.setPosition(inventoryWindow.getSize().x / 2 - telephoneText.getGlobalBounds().width / 2, 230);
								mapText.setPosition(inventoryWindow.getSize().x / 2 - mapText.getGlobalBounds().width / 2, 270);

								keyText.setPosition(inventoryWindow.getSize().x / 2 - keyText.getGlobalBounds().width / 2, 310);
								shovelText.setPosition(inventoryWindow.getSize().x / 2 - shovelText.getGlobalBounds().width / 2, 350);


								


								inventoryWindow.draw(poisonText);
								inventoryWindow.draw(telephoneText);
								inventoryWindow.draw(mapText);
								inventoryWindow.draw(swordText);
								inventoryWindow.draw(keyText);
								inventoryWindow.draw(shovelText);


								inventoryWindow.display();
								Event MouseEvent;
								while (inventoryWindow.pollEvent(MouseEvent))
								{
									if (MouseEvent.type == Event::Closed)
									{
										inventoryWindow.close();
									}

									if (MouseEvent.type == Event::MouseButtonPressed)
									{
										if (MouseEvent.mouseButton.button == Mouse::Left)
										{
											if (swordText.getGlobalBounds().contains(Vector2f(MouseEvent.mouseButton.x, MouseEvent.mouseButton.y)))
											{
												if (objAvl.SearchInInventory(5))
												{
													cout << "Player has taken Sword from inventory, removing it from inventory" << endl;
													objAvl.remove(5, "sword");
													hasSword = true;
													inventoryWindow.close();
												}
												else
												{
													cout << "Player currently has no sword" << endl;
													inventoryWindow.close();
												}
											}
											else if (keyText.getGlobalBounds().contains(Vector2f(MouseEvent.mouseButton.x, MouseEvent.mouseButton.y)))
											{
												if (objAvl.SearchInInventory(2))
												{
													cout << "Player has taken key from inventory, removing it from inventory" << endl;
													objAvl.remove(2, "key");
													hasKey = true;
													inventoryWindow.close();
												}
												else
												{
													cout << "Player currently has no key" << endl;
													inventoryWindow.close();
												}
											}
											else if (telephoneText.getGlobalBounds().contains(Vector2f(MouseEvent.mouseButton.x, MouseEvent.mouseButton.y)))
											{
												if (objAvl.SearchInInventory(1))
												{
													cout << "Player has taken telephone from inventory, removing it from inventory" << endl;
													objAvl.remove(1, "telephone");
													hasTelephone = true;
													inventoryWindow.close();
												}
												else
												{
													cout << "Player currently has no telephone" << endl;
													inventoryWindow.close();
												}
											}
											else if (poisonText.getGlobalBounds().contains(Vector2f(MouseEvent.mouseButton.x, MouseEvent.mouseButton.y)))
											{
												if (objAvl.SearchInInventory(0))
												{
													cout << "Player has taken poison from inventory, removing it from inventory" << endl;
													objAvl.remove(0, "poison");
													hasPoison = true;
													inventoryWindow.close();
												}
												else
												{
													cout << "Player currently has no poison" << endl;
													inventoryWindow.close();
												}
											}
											else if (mapText.getGlobalBounds().contains(Vector2f(MouseEvent.mouseButton.x, MouseEvent.mouseButton.y)))
											{
												if (objAvl.SearchInInventory(3))
												{
													cout << "Player has taken map from inventory, removing it from inventory" << endl;
													objAvl.remove(3, "maps");
													hasMap = true;
													inventoryWindow.close();
												}
												else
												{
													cout << "Player currently has no map" << endl;
													inventoryWindow.close();
												}
											}
											else if (shovelText.getGlobalBounds().contains(Vector2f(MouseEvent.mouseButton.x, MouseEvent.mouseButton.y)))
											{
												if (objAvl.SearchInInventory(9))
												{
													cout << "Player has taken shovel from inventory, removing it from inventory" << endl;
													objAvl.remove(9, "shovel");
													hasShovel = true;
													inventoryWindow.close();
												}
												else
												{
													cout << "Player currently has no shovel" << endl;
													inventoryWindow.close();
												}
											}
										}
									}
								}
							}
						}
					}
					if (hasPoison)
					{
						cout << "Player has eaten posion\nLive Lost" << endl;
						hasPoison = 0;
						playerLives = playerLives - 1;
					}
					if (hasKey)
					{
						if (player.sprite.getGlobalBounds().intersects(door.shape.getGlobalBounds()))
						{
							door.shape.setPosition(1000, 1000);
							hasKey = 0;
						}
					}
					
					//collision of player with food
					

					//collsion of player with key
					
						if (player.sprite.getGlobalBounds().intersects(key.shape.getGlobalBounds()))
						{
							cout << "Player took key" << endl;
							objAvl.insert(2, "key");  //taking key gives you increment of 2 in score
							score = score + 2;
							key.shape.setPosition(700, 700);

						}

					//collsion of player with sword

						if (player.sprite.getGlobalBounds().intersects(sword.shape.getGlobalBounds()))
						{
							cout << "Player took sword" << endl;
							objAvl.insert(5, "sword");  //taking sword gives you increment of 5 in score
							score = score + 5;
							sword.shape.setPosition(700, 700);

						}

					//collsion of player with shovel

						if (player.sprite.getGlobalBounds().intersects(shovel.shape.getGlobalBounds()))
						{
							cout << "Player took shovel" << endl;
							objAvl.insert(9, "shovel");  //taking shovel gives you increment of 9 in score
							score = score + 9;
							shovel.shape.setPosition(700, 700);

						}
                       
					//collsion of player with maps

						if (player.sprite.getGlobalBounds().intersects(maps.shape.getGlobalBounds()))
						{
							cout << "Player took map" << endl;
							objAvl.insert(3, "maps");  //taking map gives you increment of 3 in score
							score = score + 3;
							maps.shape.setPosition(700, 700);

						}

					//collsion of player with poison

						if (player.sprite.getGlobalBounds().intersects(poison.shape.getGlobalBounds()))
						{
							cout << "Player took poison" << endl;
							objAvl.insert(0, "poison");  //taking posion gives you no increment in score
							score = score + 0;
							poison.shape.setPosition(700, 700);

						}

					//collsion of player with telephone

						if (player.sprite.getGlobalBounds().intersects(telephone.shape.getGlobalBounds()))
						{
							cout << "Player took telephone" << endl;
							objAvl.insert(1, "telephone");  //taking telephone gives you increment of one in score
							score = score + 1;
							telephone.shape.setPosition(700, 700);

						}



					// UpDown movement of Enemy 1
					if (Enemy1Direction == 1)
					{
						enemy1.enemy_Sprite.move(0, -0.5);
						for (int i = 0; i < 210; i++)
						{
							if (enemy1.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy1Direction = 0;
								break;
							}
						}
					}

					if (Enemy1Direction == 0)
					{
						enemy1.enemy_Sprite.move(0, 0.5);
						for (int i = 0; i < 210; i++)
						{
							if (enemy1.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy1Direction = 1;
								break;
							}
						}
					}

					// LeftRight movement of enemy 2
					if (Enemy2Direction == 0)
					{
						enemy2.enemy_Sprite.move(0.5, 0);
						for (int i = 0; i <210; i++)
						{
							if (enemy2.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy2Direction = 1;
								break;
							}
						}
					}

					if (Enemy2Direction == 1)
					{
						enemy2.enemy_Sprite.move(-0.5, 0);
						for (int i = 0; i <210; i++)
						{
							if (enemy2.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy2Direction = 0;
								break;
							}
						}
					}

					// UpDown movement of Enemy3
					if (Enemy3Direction == 1)
					{
						enemy3.enemy_Sprite.move(0, 0.5);
						for (int i = 0; i <210; i++)
						{
							if (enemy3.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy3Direction = 0;
								break;
							}
						}
					}
					if (Enemy3Direction == 0)
					{
						enemy3.enemy_Sprite.move(0, -0.5);
						for (int i = 0; i <210; i++)
						{
							if (enemy3.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy3Direction = 1;
								break;
							}
						}
					}

					// LftRight movement of enemy4
					if (Enemy4Direction == 0)
					{
						enemy4.enemy_Sprite.move(-0.5, 0);
						for (int i = 0; i <210; i++)
						{
							if (enemy4.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy4Direction = 1;
								break;
							}
						}
					}

					if (Enemy4Direction == 1)
					{
						enemy4.enemy_Sprite.move(0.5, 0);
						for (int i = 0; i <210; i++)
						{
							if (enemy4.enemy_Sprite.getGlobalBounds().intersects(walls[i]))
							{
								Enemy4Direction = 0;
								break;
							}
						}
					}

					 EnemyHitPlayer = 0;
					if (enemy1.enemy_Sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) )
					{
						if (hasSword ==0)
						{
							playerLives--;
							EnemyHitPlayer = 1;
						}
						else if(hasSword==1)
						{
							hasSword = 0;
							enemy1.SetEnemyPosition(1000, 1000);
						}
						
					}
					if (enemy2.enemy_Sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) )
					{
						if (!hasSword)
						{
							playerLives--;
							EnemyHitPlayer = 1;
						}
						else if (hasSword == 1)
						{
							hasSword = 0;
							enemy2.SetEnemyPosition(1000, 1000);
						}
						EnemyHitPlayer = 1;
					}
					if (enemy3.enemy_Sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) )
					{
						if (!hasSword)
						{
							playerLives--;
							EnemyHitPlayer = 1;
						}
						else if (hasSword == 1)
						{
							hasSword = 0;
							enemy3.SetEnemyPosition(1000, 1000);
						}
						
					}
					if (enemy4.enemy_Sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) )
					{
						if (!hasSword)
						{
							playerLives--;
							EnemyHitPlayer = 1;
						}
						else if (hasSword == 1)
						{
							hasSword = 0;
							enemy4.SetEnemyPosition(1000, 1000);
						}
						
					}
					if (EnemyHitPlayer)
					{
						// setting player back to starting point
						if(RandomMaze==0)
						player.sprite.setPosition((3 * wall.shape.getGlobalBounds().width), (1 * wall.shape.getGlobalBounds().height));
						else if(RandomMaze==1)
						player.sprite.setPosition((1 * wall.shape.getGlobalBounds().width), (2 * wall.shape.getGlobalBounds().height));
						else if(RandomMaze==2)
						player.sprite.setPosition((1 * wall.shape.getGlobalBounds().width), (18 * wall.shape.getGlobalBounds().height));
						else
						player.sprite.setPosition((2 * wall.shape.getGlobalBounds().width), (1 * wall.shape.getGlobalBounds().height));
						EnemyHitPlayer = 0;
					}
					
					window.draw(player.sprite);
					window.draw(scores);
					window.draw(lives);

					window.display();
					timeSinceLastUpdate = sf::Time::Zero;
				}
			}

			
			
			if (hasShovel)
			{
				if (player.sprite.getGlobalBounds().intersects(exit.shape.getGlobalBounds()))
				{
					exit.shape.setPosition(1000, 1000);
					hasShovel = 0;

					window.clear();
					endGame.setString("You Win");
					window.draw(endGame);
					window.display();
					winCondition = true;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						window.close();
					}

				}
			}

			if (loseCondition == true)
			{
				
				window.clear();
				endGame.setString("You Lose");
				window.draw(endGame);
				window.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					window.close();
				}
				
				
			}
		}
	
	}
	
};
