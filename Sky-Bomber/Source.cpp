#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>


int main()
{
	float planeX = 40.0f, planeY = 80.0f;
	sf::Clock clk;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SKY BOMBER");

	sf::Texture bgtexture, groundTexture, grassTexture, stoneTexture, planeTexture;
	if (!bgtexture.loadFromFile("background.png") || !groundTexture.loadFromFile("ground.png"))
		std::cout << "Cannot load from file";
	if (!grassTexture.loadFromFile("grass.png") || !stoneTexture.loadFromFile("stone.png"))
		std::cout << "Cannot open from file";
	if (!planeTexture.loadFromFile("plane.png"))
		std::cout << "Cannot open from file";
	sf::Sprite bgsprite, groundSprite, grassSprite, stoneSprite,planeSprite;
	bgsprite.setTexture(bgtexture);
	groundSprite.setTexture(groundTexture);
	grassSprite.setTexture(grassTexture);
	stoneSprite.setTexture(stoneTexture);
	planeSprite.setTexture(planeTexture);
	sf::Vector2u sizeGround = groundTexture.getSize();
	sf::Vector2u sizeGrass = grassTexture.getSize();
	sf::Vector2u sizeStone = stoneTexture.getSize();
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
		//check
		planeSprite.setPosition(sf::Vector2f(planeX, planeY));
	
		if (clk.getElapsedTime().asMicroseconds() > 1.0f)
		{
			if (planeX > 800)
				planeX = 0;

			planeX = planeX + 0.5f;
			planeSprite.setPosition(sf::Vector2f(planeX, planeY));
			clk.restart();
		}
		window.draw(planeSprite);
		window.display();


	}
	return 0;
}