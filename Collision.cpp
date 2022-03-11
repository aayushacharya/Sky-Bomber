#include "../Collision.h"
#include<SFML/Graphics.hpp>
#define TOLERANCE 50
bool Collision::Detect(sf::Sprite* missile, sf::Sprite* GameObj)
{
	sf::Vector2f missilePos, GameObjPos;
	missilePos = missile->getPosition();
	GameObjPos = GameObj->getPosition();
	bool xTrue = false;
	bool yTrue = false;
	if (missilePos.x < (GameObjPos.x + TOLERANCE) && missilePos.x>(GameObjPos.x - TOLERANCE))
	{
		xTrue = true;
	}
	if (missilePos.y < (GameObjPos.y + TOLERANCE) && missilePos.y > (GameObjPos.y - TOLERANCE))
	{
		yTrue = true;
	}
	if (xTrue && yTrue)
	{
		return true;
	}
	return false;
}