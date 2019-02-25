#include "../Missile.h"
#include <SFML/Graphics.hpp>
void Missile::move(sf::Sprite* s,float *y) {
	static float acc=0.0f;
	if (s->getRotation() < 90)
	{
		s->rotate(5.0f);
	}
	else if (s->getRotation() > 90)
	{
		s->rotate(-5.0f);
	}
	else if (s->getRotation() > 75 && s->getRotation() < 105)
	{
		s->setRotation(90.0f);
	}
	

	*y = *y + acc;
	acc += 0.1f;
}