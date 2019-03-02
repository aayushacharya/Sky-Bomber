#include<SFML/Graphics.hpp>
#include <iostream>
#include "../Tank.h"
Tank::Tank()
{
	x = 0.0f, y = 0.0f;
	offsetX = 0.0f;
	if (!tankTexture.loadFromFile("resources/tank.png"))
	{
		std::cout << "Couldn't load from file";
	}
	tankSprite.setTexture(tankTexture);
}
Tank::Tank(sf::Texture& tankText)
{
	tankSprite.setTexture(tankText);
}
void Tank::setTexture(sf::Texture& tankText)
{
	tankSprite.setTexture(tankText);
}
void Tank::setPosition(sf::Vector2f pos)
{
	tankSprite.setPosition(sf::Vector2f(pos.x, pos.y));
}
sf::Vector2f Tank::getPosition()
{
	return tankSprite.getPosition();
}
void Tank::setScale(sf::Vector2f scale)
{
	return tankSprite.setScale(sf::Vector2f(scale.x, scale.y));
}
sf::Sprite& Tank::getAddress()
{
	return tankSprite;
}
void Tank::draw(sf::RenderWindow& window)
{
	window.draw(tankSprite);
}