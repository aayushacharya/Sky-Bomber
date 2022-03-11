#include"../Boundary.h"
#include<SFML/Graphics.hpp>
#include<iostream>
void GameObj::Boundary::Check(sf::Sprite& Obj,float& objX, float& off,std::string pos)
{
	if (pos == "right")
	{
		if (objX < 0)
		{
			Obj.setScale(sf::Vector2f(1.0f, 1.0f));
			off = fabsf(off);
		}
		if (objX > 1360)
		{
			Obj.setScale(sf::Vector2f(-1.0f, 1.0f));
			off = -fabsf(off);
		}
	}
	if (pos == "left")
	{
		if (objX < 0)
		{
			Obj.setScale(sf::Vector2f(-1.0f, 1.0f));
			off = fabsf(off);
		}
		if (objX> 1360)
		{
			Obj.setScale(sf::Vector2f(1.0f, 1.0f));
			off = -fabsf(off);
		}
	}
}
