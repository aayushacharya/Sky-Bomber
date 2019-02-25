#include "../Missile.h"
#include <SFML/Graphics.hpp>
#include<iostream>
void Missile::move(sf::Sprite* s,float *y,std::string pos) {
	static float acc=0.0f;
	float angle;
	float offset=5.0f;
	if (pos == "right")
	{
		angle = 90.0f;
	}
	if (pos == "left")
	{
		angle = 270.0f;
	}
	if (s->getRotation() < angle)
	{
		s->rotate(offset);
	}
	else if (s->getRotation() > angle)
	{
		s->rotate(-offset);
	}
	else if (s->getRotation() > (angle-15) && s->getRotation() < (angle+15))
	{
		s->setRotation(angle);
	}
	

	*y = *y + acc;
	acc += 0.1f;
}