#include <iostream>
#include <string>
#include "../HighScoreScreen.h"
#include <SFML/Graphics.hpp>
#include "../GameEngine.h"
#include "../HighScore.h"
#define width 1366
#define height 768
void Screen::HighScore()
{
	sf::Texture highscoreTexture;
	if (!highscoreTexture.loadFromFile("resources/background.png"))
		std::cout << "Not working" << std::endl;

	sf::Sprite HST;
	HST.setTexture(highscoreTexture);

	sf::RenderWindow app(sf::VideoMode(1366, 768), "High Score");
	sf::Font font;
	if (!font.loadFromFile("resources/numberfont.ttf"))
	{
		std::cout << "Couldn't load font";
	}
	sf::Text heading;
	sf::Text text[3];
	std::string getName[3];
	std::string getScore[3];
	Highscore::Get(getName, getScore);
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
		for (int i = 0;i < 3;i++)
		{
		
			std::transform(getName[i].begin(), getName[i].end(), getName[i].begin(), ::toupper);
		}
		heading.setFont(font);
		heading.setColor(sf::Color::Black);
		heading.setString("HIGHSCORES");
		heading.setScale(3, 3);
		heading.setPosition(sf::Vector2f(width / 4, height / 6));

		text[0].setFont(font);
		text[0].setColor(sf::Color::Red);
		text[0].setString(getName[0] +"\t\t\t" +getScore[0]);
		text[0].setScale(2, 2);
		text[0].setPosition(sf::Vector2f(width / 8, height / 3));

		text[1].setFont(font);
		text[1].setColor(sf::Color::Blue);
		text[1].setString(getName[1] + "\t\t\t" + getScore[1]);
		text[1].setScale(2, 2);
		text[1].setPosition(sf::Vector2f(width / 8, height / 2));

		text[2].setFont(font);
		text[2].setColor(sf::Color::Yellow);
		text[2].setString(getName[2] + "\t\t\t" + getScore[2]);
		text[2].setScale(2, 2);
		text[2].setPosition(sf::Vector2f(width / 8, height / 1.5));

		app.clear();
		app.draw(HST);
		app.draw(heading);
		app.draw(text[0]);
		app.draw(text[1]);
		app.draw(text[2]);
		app.display();
	}

}