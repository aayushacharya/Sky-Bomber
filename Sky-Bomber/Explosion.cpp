#include "../Explosion.h"
#include<iostream>
#include <SFML/Graphics.hpp>
void Explosion::Create(float ObjX,float ObjY,sf::RenderWindow& window)
{
	static float xPos=ObjX, yPos=ObjX;
	sf::Texture explosionText;
	if (!explosionText.loadFromFile("resources/explosion.png"))
	{
		std::cout << "Cannot load explosion" << std::endl;
	}
	sf::Sprite explosionSprite;
	int width=90;
	int height = 90;
	int counter = 0;
	static int x, y;
	x = 0, y = 0;
	explosionSprite.setTextureRect(sf::IntRect(x, y, width, height));
	explosionSprite.setPosition(sf::Vector2f(xPos, yPos));
	x += width;
	if (x > 450)
	{
		x = 0;
		y = 90;
		counter++;
	}
	if (counter == 2)
	{
		counter = 0;
		x = 0;
		y = 0;
	}
	window.draw(explosionSprite);
}