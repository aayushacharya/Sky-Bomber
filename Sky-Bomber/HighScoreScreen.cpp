#include <iostream>
#include "../HighScoreScreen.h"
#include <SFML/Graphics.hpp>
#include "../GameEngine.h"

void Screen::HighScore()
{
	sf::Texture highscoreTexture;
	if (!highscoreTexture.loadFromFile("resources/background.png"))
		std::cout << "Not working" << std::endl;

	sf::Sprite HST;
	HST.setTexture(highscoreTexture);

	sf::RenderWindow app(sf::VideoMode(1366, 768), "High Score");

	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				app.close();
				Game::start();
			}

		}
		app.clear();
		app.draw(HST);
		app.display();
	}

}