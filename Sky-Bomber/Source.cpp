#include<iostream>
#include <SFML/Graphics.hpp>


int main()
{
	/*float rectX=10.0f, rectY=20.0f;*/
	sf::RenderWindow window(sf::VideoMode(800, 600), "SKY BOMBER");

	sf::Texture bgtexture, groundTexture, grassTexture, stoneTexture;
	if (!bgtexture.loadFromFile("background.png") || !groundTexture.loadFromFile("ground.png"))
		std::cout << "Cannot load from file";
	if (!grassTexture.loadFromFile("grass.png") || !stoneTexture.loadFromFile("stone.png"))
		std::cout << "Cannot open from file";
	sf::Sprite bgsprite, groundSprite, grassSprite, stoneSprite;
	bgsprite.setTexture(bgtexture);
	groundSprite.setTexture(groundTexture);
	grassSprite.setTexture(grassTexture);
	stoneSprite.setTexture(stoneTexture);
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
				// window closed
			case sf::Event::Closed:
				window.close();
				break;

				// key pressed


				// we don't process other types of events
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

		window.display();


	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
			rectangle.move(sf::Vector2f(0.1f, 0.0f));
			triangle.move(sf::Vector2f(0.1f, 0.0f));
	}*/






	return 0;
}