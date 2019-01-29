#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>


int main()
{
	float planeX = 40.0f, planeY = 80.0f;
	float truckX = 700.0f, truckY = 480.0f;
	float planeOffsetX = 0.5f, truckOffsetX = 0.3f;
	sf::Clock clk;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SKY BOMBER");

	sf::Texture bgtexture, groundTexture, grassTexture, stoneTexture, planeTexture;
	sf::Texture mTruckTexture;
	if (!bgtexture.loadFromFile("background.png") || !groundTexture.loadFromFile("ground.png"))
		std::cout << "Cannot load from file";
	if (!grassTexture.loadFromFile("grass.png") || !stoneTexture.loadFromFile("stone.png"))
		std::cout << "Cannot open from file";
	if (!planeTexture.loadFromFile("plane.png"))
		std::cout << "Cannot open from file";
	sf::Sprite bgsprite, groundSprite, grassSprite, stoneSprite,planeSprite,mTruckSprite;
	if (!mTruckTexture.loadFromFile("mtruck.png"))
		std::cout<<"Cannot load from file";
	mTruckSprite.setTexture(mTruckTexture);
	bgsprite.setTexture(bgtexture);
	groundSprite.setTexture(groundTexture);
	grassSprite.setTexture(grassTexture);
	stoneSprite.setTexture(stoneTexture);
	planeSprite.setTexture(planeTexture);
	sf::Vector2u sizeGround = groundTexture.getSize();
	sf::Vector2u sizeGrass = grassTexture.getSize();
	sf::Vector2u sizeStone = stoneTexture.getSize();
	sf::Vector2u sizemTruck = mTruckTexture.getSize();
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
		float screenX = 0.0f, screenY = 480.0f;
		while (1)
		{
			if (screenX > 800)
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
			if (screenX > 800 && screenY > 600)
				break;
			if (screenX > 800)
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
		if (clk.getElapsedTime().asMicroseconds() > 1.0f)
		{
			if (planeX > 780) {
				planeSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
				planeOffsetX = -0.5f;
			}
			if (planeX < 0)
			{
				planeSprite.setScale(sf::Vector2f(1.0f, 1.0f));
				planeOffsetX = 0.5f;
			}
			if (truckX < 0)
			{
				mTruckSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
				truckOffsetX = -0.3f;
			}
			if (truckX > 780)
			{
				mTruckSprite.setScale(sf::Vector2f(1.0f, 1.0f));
				truckOffsetX = 0.3f;
			}
				
			planeX = planeX + planeOffsetX;
			truckX = truckX - truckOffsetX;
			planeSprite.setPosition(sf::Vector2f(planeX, planeY));
			mTruckSprite.setPosition(sf::Vector2f(truckX, truckY-sizeStone.y - sizeGrass.y - sizemTruck.y));
			clk.restart();
		}
		window.draw(planeSprite);
		window.draw(mTruckSprite);
		window.display();


	}
	return 0;
}