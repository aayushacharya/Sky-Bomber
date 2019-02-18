#include<iostream>
#include<cmath>
#include <SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
float checkBoundary(sf::Sprite&, float,float);
void velocity(float*, float*);
void speed();
int main()
{
	
	float planeX = 40.0f, planeY = 80.0f;
	float *Xplane,*Yplane,*planeXOffset, *planeYOffset;
	float upRotate, downRotate;
	float truckX = 700.0f, truckY = 600.0f;
	float tankX = 30.0f, tankY = 600.0f;
	float planeOffsetX = 0.5f, truckOffsetX = 0.3f;
	float tankOffsetX = 0.4f;
	float planeOffsetY = 0.5f;
	Xplane = &planeX;
	planeXOffset = &planeOffsetX;
	sf::Clock clk;
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SKY BOMBER");

	sf::Texture bgtexture, groundTexture, grassTexture, stoneTexture, planeTexture;
	sf::Texture mTruckTexture,tankTexture;
	if (!bgtexture.loadFromFile("resources/BG.png") || !groundTexture.loadFromFile("resources/ground.png"))
		std::cout << "Cannot load from file";
	if (!grassTexture.loadFromFile("resources/grass.png") || !stoneTexture.loadFromFile("resources/stone.png"))
		std::cout << "Cannot open from file";
	if (!planeTexture.loadFromFile("resources/plane3.png"))
		std::cout << "Cannot open from file";
	sf::Sprite bgsprite, groundSprite, grassSprite, stoneSprite,planeSprite,mTruckSprite;
	sf::Sprite tankSprite;
	if (!mTruckTexture.loadFromFile("resources/mtruck.png") || !tankTexture.loadFromFile("resources/tank.png"))
		std::cout<<"Cannot load from file";
	mTruckSprite.setTexture(mTruckTexture);
	bgsprite.setTexture(bgtexture);
	groundSprite.setTexture(groundTexture);
	grassSprite.setTexture(grassTexture);
	stoneSprite.setTexture(stoneTexture);
	planeSprite.setTexture(planeTexture);
	tankSprite.setTexture(tankTexture);
	sf::Vector2u sizeGround = groundTexture.getSize();
	sf::Vector2u sizeGrass = grassTexture.getSize();
	sf::Vector2u sizeStone = stoneTexture.getSize();
	sf::Vector2u sizemTruck = mTruckTexture.getSize();
	sf::Vector2u sizeTank = tankTexture.getSize();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
	
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color::Black);
		window.draw(bgsprite);
		float screenX = 0.0f, screenY = 600.0f;
		while (1)
		{
			if (screenX > 1366)
			{
				break;
			}
			grassSprite.setPosition(sf::Vector2f(screenX, screenY - sizeGrass.y));
			stoneSprite.setPosition(sf::Vector2f(screenX, screenY - sizeStone.y - sizeGrass.y));
			window.draw(grassSprite);
			window.draw(stoneSprite);
			screenX += sizeStone.x;
		}
		
		screenX = 0.0f;
		while (1)
		{
			if (screenX > 1366 && screenY > 768)
				break;
			if (screenX > 1366)
			{
				screenX = 0;
				screenY += sizeGround.y;
			}
			groundSprite.setPosition(sf::Vector2f(screenX, screenY));
			window.draw(groundSprite);
			screenX += sizeGround.x;
		}
		
		planeSprite.setPosition(sf::Vector2f(planeX, planeY));
		mTruckSprite.setPosition(sf::Vector2f(truckX, truckY - sizeStone.y - sizeGrass.y - sizemTruck.y));
		tankSprite.setPosition(sf::Vector2f(tankX, tankY - sizeStone.y - sizeGrass.y - sizeTank.y+5.0f));
		if (clk.getElapsedTime().asMicroseconds() > 1.0f)
		{
			//planeOffsetX = checkBoundary(planeSprite, planeOffsetX,planeX);
			//truckOffsetX = checkBoundary(mTruckSprite, truckOffsetX,truckX);
			//todo boundary conditions check, see if offset is needed
			if (planeX < 0)
			{
				planeSprite.setScale(sf::Vector2f(1.0f, 1.0f));
				planeOffsetX = 0.5f;
			}
			if (planeX > 1360)
			{
				planeSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
				planeOffsetX = -0.5f;
			}
			if (planeY > (screenY-sizeGround.y-sizeStone.y-sizeGrass.y-180.0f))
			{
				planeSprite.setRotation(270.0f);
				planeOffsetY = -0.5f;
			}
			if (planeY < 0)
			{
				planeSprite.setRotation(90.0f);
				planeOffsetY = 0.5f;
			}
			if (truckX < 0)
			{
				mTruckSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
				truckOffsetX = -0.3f;
			}
			if (truckX > 1360)
			{
				mTruckSprite.setScale(sf::Vector2f(1.0f, 1.0f));
				truckOffsetX = 0.3f;
			}
			if (tankX < 0)
			{
				tankSprite.setScale(sf::Vector2f(1.0f, 1.0f));
				tankOffsetX = 0.4f;
			}
			if (tankX > 1360)
			{
				tankSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
				tankOffsetX = -0.4f;
			}
			//check
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				planeSprite.rotate(-0.5f);
				//planeSprite.setRotation(0.0f);
				//planeSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
				/*if (planeOffsetX > 0)
				{
					planeOffsetX = -planeOffsetX;
				}*/
				//plane = &planeX;
				//planeOffset = &planeOffsetX;
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				planeSprite.rotate(0.5f);
				//planeSprite.setRotation(0.0f);
				//planeSprite.setScale(sf::Vector2f(1.0f, 1.0f));
				//planeOffsetX = fabsf(planeOffsetX);
				//Xplane = &planeX;
				//planeXOffset = &planeOffsetX;
				
			}
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				//if planeOffsetX is negative then -90			
				upRotate = planeSprite.getRotation();
				if ((int)upRotate < 270)
				{
					if ((int)upRotate > 265)
					{
						upRotate = 270.0f;
						upRotate = planeSprite.getRotation();
					}
					else
					{
					planeSprite.rotate(0.5f);
					upRotate = planeSprite.getRotation();
					}
				}
				if ((int)upRotate > 270)
				{
					if ((int)upRotate < 275)
					{
						upRotate = 270.0f;
						upRotate = planeSprite.getRotation();
					}
					else {
						planeSprite.rotate(-0.5f);
						upRotate = planeSprite.getRotation();
					}
				}
				
				planeSprite.setRotation(upRotate);
				
				planeOffsetY = -fabsf(planeOffsetY);
				//todo from here
				plane = &planeY;
				planeOffset = &planeOffsetY;
				
			}*/
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				
				downRotate=planeSprite.getRotation();
				if ((int)downRotate < 90)
				{
					if ((int)downRotate > 85)
					{
						downRotate = 90.0f;
						downRotate = planeSprite.getRotation();
					}
					else {
						planeSprite.rotate(0.5f);
						downRotate = planeSprite.getRotation();
					}
				}
				if ((int)downRotate > 90)
				{
					if ((int)downRotate < 95)
					{
						downRotate = 90.0f;
						downRotate = planeSprite.getRotation();
					}
					else {
						planeSprite.rotate(-0.5f);
						downRotate = planeSprite.getRotation();
					}
				}
				planeSprite.setRotation(downRotate);			
				planeOffsetY = fabsf(planeOffsetY);
				//todo
				plane = &planeY;
				planeOffset = &planeOffsetY;
				
			}*/
			planeOffsetX = cos(planeSprite.getRotation())*0.5f;
			planeOffsetY = sin(planeSprite.getRotation())*0.5f;
			velocity(&planeX, &planeOffsetX);
			velocity(&planeY, &planeOffsetY);
			truckX = truckX - truckOffsetX;
			tankX = tankX + tankOffsetX;
			clk.restart();
		}
		window.draw(planeSprite);
		window.draw(mTruckSprite);
		window.draw(tankSprite);
		window.display();


	}
	return 0;
}
float checkBoundary(sf::Sprite& s, float offX,float xPos)//check
{
	static float X=offX;
	if (xPos > 1360) {
		s.setScale(sf::Vector2f(-1.0f, 1.0f));
		X = -offX;
	
		
	}
	if (xPos < 0)
	{
		s.setScale(sf::Vector2f(1.0f, 1.0f));
		X=offX;
	
	}
	return X;
}
void velocity(float* x, float* offsetX)
{
	*x += *offsetX;
}