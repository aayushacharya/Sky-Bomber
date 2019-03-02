#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class GroundMissile
{
private:
	sf::Sprite missileSprite;
	sf::Sprite missileBase;
	sf::Texture missileText, missileBaseText;
public:
	GroundMissile();
	void setMissilePosition(sf::Vector2f);
	sf::Vector2f getMissilePosition();
	void setBasePosition(sf::Vector2f);
	sf::Vector2f getBasePosition();
	void moveMissile(sf::Vector2f);
	void drawMissile(sf::RenderWindow&);
	void setMissileRotation(float);
	void drawBase(sf::RenderWindow&);
	sf::Sprite* getBaseAddress();
};
