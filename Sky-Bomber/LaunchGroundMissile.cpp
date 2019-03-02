#include"../LaunchGroundMissile.h"
#include"../GroundMissile.h"
#include"../Collision.h"
#include"../Explosion.h"
#include<SFML/Graphics.hpp>
#include<cmath>
#define SPEED 5.5f
void Launch::Missile(sf::Sprite& plane, sf::Sprite* planeMissile,sf::RenderWindow& window)
{
	static int counter = 4;
	static GroundMissile gm1;
	static float angle;	//in radian
	static bool baseBlasted = false;
	if (!Collision::Detect(planeMissile, gm1.getBaseAddress()))
	{
		if (counter > 3 && baseBlasted==false)
		{
			sf::Vector2f planePos = plane.getPosition();
			sf::Vector2f groundMissilePos = gm1.getMissilePosition();
			if (planePos.x == groundMissilePos.x)
			{
				angle = 90.0f*3.1412f / 180.0f;
			}
			else
			{
				angle = -(planePos.y - groundMissilePos.y) / (planePos.x - groundMissilePos.x);
			}

			counter = 0;
		}
		if (!baseBlasted)
		{
			counter++;
		}
		gm1.setMissileRotation(angle);
		gm1.moveMissile(sf::Vector2f(SPEED*cos(angle), SPEED*sin(3.1412f + angle)));
		gm1.drawBase(window);
		gm1.drawMissile(window);
	}
	else
	{
		baseBlasted = true;
	}
	if (baseBlasted)
	{
		sf::Vector2f basePos=gm1.getBasePosition();
		//Explosion::Create(basePos.x, basePos.y, window, "tank1", 0);
		gm1.setBasePosition(sf::Vector2f(-100.0f, -100.0f));
	}
	
}