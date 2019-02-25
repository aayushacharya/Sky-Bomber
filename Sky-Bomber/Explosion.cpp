#include "../Explosion.h"
#include<iostream>
#include <SFML/Graphics.hpp>
void Explosion::Create(float ObjX,float ObjY,sf::RenderWindow& window)
{
	float xPos=ObjX, yPos=ObjY;
	sf::Texture explosionText;
	if (!explosionText.loadFromFile("resources/explosion.png"))
	{
		std::cout << "Cannot load explosion" << std::endl;
	}
	int width=64;
	int height = 64;
	int counter = 0;
	static int x, y;
	x = 0, y = 0;
	sf::Sprite explosionSprite(explosionText,sf::IntRect(x, y, width, height));
	explosionSprite.setPosition(sf::Vector2f(xPos, yPos-50.0f));
	x += width;
	if (x > (64*4))
	{
		x = 0;
		y += 64;
		counter++;
	}
	if (counter == 3)
	{
		counter = 0;
		x = 0;
		y = 0;
	}
	window.draw(explosionSprite);
}