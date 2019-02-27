#include "../Explosion.h"
#include<iostream>
#include <SFML/Graphics.hpp>
void Explosion::Create(float ObjX,float ObjY,sf::RenderWindow& window,std::string GameObj,int no)
{
	float xPos = ObjX;
	float yPos=ObjY;
	static std::string ObjName=GameObj;
	static int objNum = no;
	sf::Texture explosionText;
	if (!explosionText.loadFromFile("resources/explosion.png"))
	{
		std::cout << "Cannot load explosion" << std::endl;
	}
	int width=64;
	int height = 64;
	static int counter = 0;
	static int x = 0;
	static int y = 0;
	sf::Sprite explosionSprite(explosionText,sf::IntRect(x, y, width, height));
	explosionSprite.setPosition(sf::Vector2f(xPos, yPos-50.0f));
	window.draw(explosionSprite);
	x += width;
	if (x > (64*4))
	{
		x = 0;
		y += 64;
		counter++;
	}
	if (counter > 2)
	{
		if (ObjName == GameObj && objNum==no)
		{
		}
		else
		{
			ObjName = GameObj;
			objNum = no;
			counter = 0;
			x = 0;
			y = 0;
		}
	}
	
}