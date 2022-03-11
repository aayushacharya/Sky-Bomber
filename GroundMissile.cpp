#include"../GroundMissile.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Graphics.hpp>
#include"../GroundMissile.h"
GroundMissile::GroundMissile()
{
	
	if (!missileText.loadFromFile("resources/groundmissile.png") || !missileBaseText.loadFromFile("resources/missilebase.png"))
	{
		std::cout << "Couldn't load from file";
	}
	missileBase.setTexture(missileBaseText);
	missileSprite.setTexture(missileText);
	missileBase.setPosition(sf::Vector2f(400.0f, 550.0f));
	missileSprite.setPosition(sf::Vector2f(400.0f, 550.0f));
}
void GroundMissile::setMissilePosition(sf::Vector2f pos)
{
	missileSprite.setPosition(sf::Vector2f(pos.x, pos.y));
}
sf::Vector2f GroundMissile::getMissilePosition()
{
	return missileSprite.getPosition();
}
void GroundMissile::setBasePosition(sf::Vector2f pos)
{
	missileBase.setPosition(sf::Vector2f(pos.x, pos.y));
}
void GroundMissile::setMissileRotation(float angle)
{
	missileSprite.setRotation(angle*180.0f/3.14f);
}
sf::Vector2f GroundMissile::getBasePosition()
{
	return missileBase.getPosition();
}
void GroundMissile::moveMissile(sf::Vector2f off)
{
	missileSprite.move(sf::Vector2f(off.x, off.y));
}
void GroundMissile::drawMissile(sf::RenderWindow& window)
{
	window.draw(missileSprite);
}
void GroundMissile::drawBase(sf::RenderWindow& window)
{
	window.draw(missileBase);
}
sf::Sprite* GroundMissile::getBaseAddress()
{
	return &missileBase;
}