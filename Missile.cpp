#include "../Missile.h"
#include <SFML/Graphics.hpp>
#include<iostream>
void Missile::move(sf::Sprite* s,float *velocityY,std::string pos) {
	static float gt=0.0f;
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
	

	*velocityY = *velocityY + gt;
	gt += 0.1f;
	if (*velocityY > 680.0f)
	{
		gt = 0.0f;
	}
}