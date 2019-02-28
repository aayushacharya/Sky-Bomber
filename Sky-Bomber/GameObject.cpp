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

FuelCheck fuelcheck;
void Level1::Start(sf::Texture& tank1, sf::Texture& tank2, sf::Sprite* missileSprite, sf::RenderWindow& window)
{
	int flag = 1;
	static int flag1 = 1;
	static float tank1X[5] = { 700.0f,700.0f,700.0f,700.0f,700.0f }, tank1Y[5] = { 680.0f,680.0f,680.0f,680.0f,680.0f };
	static float tank2X[5] = { 30.0f,30.0f,30.0f,30.0f,30.0f }, tank2Y[5] = { 680.0f,680.0f,680.0f,680.0f,680.0f };
	static float tank1OffsetX[5] = { -4.0f,-4.0f,-4.0f,-4.0f,-4.0f };
	static float tank2OffsetX[5] = { 3.0f,3.0f,3.0f,3.0f,3.0f };
	static sf::Sprite tank1Sprite[5];
	static sf::Sprite tank2Sprite[5];
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
			tank1Sprite[i].setTexture(tank1);
			tank2Sprite[i].setTexture(tank2);
		}
		if (!explosion.openFromFile("resources/Explosion.wav"))
			std::cout << "sound not streamed" << std::endl;

	}
	initialization = false;
	//todo 
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
		GameObj::Boundary::Check(tank1Sprite[i], tank1X[i], tank1OffsetX[i], "left");
		GameObj::Boundary::Check(tank2Sprite[i], tank2X[i], tank2OffsetX[i], "right");
		tank1Sprite[i].setPosition(sf::Vector2f(tank1X[i], tank1Y[i]));
		tank2Sprite[i].setPosition(sf::Vector2f(tank2X[i], tank2Y[i]));
		if (Collision::Detect(missileSprite, &tank1Sprite[i]))
		{
			score += 100;
			fuelcheck.isFinished(true);
			tank2Collision = false;
			tank1_CollisionX = tank1X[i];
			tank1Collision = true;
			collisionObj = i;
			Explosion::Create(tank1_CollisionX, 680.0f, window, "tank1", collisionObj);
			explosion.play();
			tank1OffsetX[i] = 0;
			tank1X[i] = -100;
			tank1CollisionRecord[i] = true;

		}
		if (tank1Collision)
		{

			Explosion::Create(tank1_CollisionX, 680.0f, window, "tank1", collisionObj);

		}
		if (!tank1CollisionRecord[i])
		{
			window.draw(tank1Sprite[i]);
		}
		if (Collision::Detect(missileSprite, &tank2Sprite[i]))
		{
			score += 100;
			fuelcheck.isFinished(true);
			collisionObj = i;
			tank2_CollisionX = tank2X[i];
			tank2Collision = true;
			Explosion::Create(tank2_CollisionX, 680.0f, window, "tank2", collisionObj);
			explosion.play();
			tank2OffsetX[i] = 0;
			tank2X[i] = -100;
			tank1Collision = false;
			tank2CollisionRecord[i] = true;

		}
		if (tank2Collision)
		{
			Explosion::Create(tank2_CollisionX, 680.0f, window, "tank2", collisionObj);
		}
		if (!tank2CollisionRecord[i])
		{
			window.draw(tank2Sprite[i]);
		}
		tank1X[i] += tank1OffsetX[i];
		tank2X[i] += tank2OffsetX[i];
		
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