#include "../MainMenu.h"
#include <SFML/Audio.hpp>

Menu::Menu(float width, float height)
{


	if (!font.loadFromFile("resources/mainmenufont.ttf"))
	{
		std::cout << "Loading Failed" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Green);
	menu[0].setString("START GAME");
	menu[0].setScale(2,2);
	menu[0].setPosition(sf::Vector2f(width / 8, height /  3));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("HIGHSCORE");
	menu[1].setScale(2,2);
	menu[1].setPosition(sf::Vector2f(width / 8, height /  2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("EXIT");
	menu[2].setScale(2,2);
	menu[2].setPosition(sf::Vector2f(width / 8, height /  1.5));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}
