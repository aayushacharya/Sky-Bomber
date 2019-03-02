#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
#include"../GameObject.h"
#include"../Boundary.h"
#include"../Collision.h"
#include"../Explosion.h"
#include "SFML/Audio.hpp"
#include"../FuelCheck.h"
#include "../HighScore.h"
#include"../Tank.h"
FuelCheck fuelcheck;
void Level1::Start(sf::Texture& tank1Text, sf::Texture& tank2Text, sf::Sprite* missileSprite, sf::RenderWindow& window)
{
	int flag = 1;
	static int flag1 = 1;
	static Tank tank1[5], tank2[5];
	static bool initialization = true;
	static bool allGameObjSent = false;
	static int counter = 1;
	static float tank1_CollisionX, tank2_CollisionX;
	static bool tank1Collision = false, tank2Collision = false;
	static bool tank1CollisionRecord[5] = { false,false,false,false,false };
	static bool tank2CollisionRecord[5] = { false,false,false,false,false };
	static sf::Music explosion;
	static int collisionObj;
	static int score=0;
	if (initialization)
	{
		for (int i = 0; i < 5; i++)
		{
			
			tank1[i].setTexture(tank1Text);
			tank1[i].x = 700.0f;
			tank1[i].offsetX = -4.0f;
			tank2[i].setTexture(tank2Text);
			tank2[i].x = 30.0f;
			tank2[i].offsetX = 3.0f;
			tank1[i].y = 680.0f, tank2[i].y = 680.0f;
		}
		if (!explosion.openFromFile("resources/Explosion.wav"))
			std::cout << "sound not streamed" << std::endl;

	}
	initialization = false;
	
	static sf::Clock clk;
	if (clk.getElapsedTime().asSeconds() > 10.0f)
	{
		if (!allGameObjSent)
		{
			++counter;
			if (counter > 4)
			{
				allGameObjSent = true;
			}
		}
		clk.restart();
	}

	for (int i = 0; i < counter; i++)
	{
		GameObj::Boundary::Check(tank1[i].getAddress(), tank1[i].x, tank1[i].offsetX, "left");
		GameObj::Boundary::Check(tank2[i].getAddress(), tank2[i].x, tank2[i].offsetX, "right");
		tank1[i].setPosition(sf::Vector2f(tank1[i].x, tank1[i].y));
		tank2[i].setPosition(sf::Vector2f(tank2[i].x, tank2[i].y));
		if (Collision::Detect(missileSprite, &tank1[i].getAddress()))
		{
			score += 100;
			fuelcheck.isFinished(true);
			tank2Collision = false;
			tank1_CollisionX = tank1[i].x;
			tank1Collision = true;
			collisionObj = i;
			Explosion::Create(tank1_CollisionX, 680.0f, window, "tank1", collisionObj);
			explosion.play();
			tank1[i].offsetX = 0;
			tank1[i].x = -100;
			tank1CollisionRecord[i] = true;

		}
		if (tank1Collision)
		{

			Explosion::Create(tank1_CollisionX, 680.0f, window, "tank1", collisionObj);

		}
		if (!tank1CollisionRecord[i])
		{
			tank1[i].draw(window);
		}
		if (Collision::Detect(missileSprite, &tank2[i].getAddress()))
		{
			score += 100;
			fuelcheck.isFinished(true);
			collisionObj = i;
			tank2_CollisionX = tank2[i].x;
			tank2Collision = true;
			Explosion::Create(tank2_CollisionX, 680.0f, window, "tank2", collisionObj);
			explosion.play();
			tank2[i].offsetX = 0;
			tank2[i].x = -100;
			tank1Collision = false;
			tank2CollisionRecord[i] = true;

		}
		if (tank2Collision)
		{
			Explosion::Create(tank2_CollisionX, 680.0f, window, "tank2", collisionObj);
		}
		if (!tank2CollisionRecord[i])
		{
			tank2[i].draw(window);
		}
		tank1[i].x += tank1[i].offsetX;
		tank2[i].x += tank2[i].offsetX;
		
	}
	for (int i = 0;i < 5;i++)
	{
		if (tank1CollisionRecord[i] == false || tank2CollisionRecord[i] == false)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		//Level1 Completed
		if (flag1)
		{
			Highscore::Save(score);
			flag1 = 0;
		}

	}
	Level1::sendScore(score);
	fuelcheck.isFinished(false);



}
int Level1::sendScore(int score)
{
	static int scoreCount;
	if (score == 1)
	{
		return scoreCount;
	}
	scoreCount = score;
	return score;
}