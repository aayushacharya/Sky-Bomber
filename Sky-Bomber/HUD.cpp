#include "../HUD.h"
#include <SFML/Audio.hpp>

LifeFuel::LifeFuel(float width, float height)
{


	if (!font.loadFromFile("resources/numberfont.ttf"))
	{
		std::cout << "Loading Failed" << std::endl;
	}

	Lifefuel[0].setFont(font);
	Lifefuel[0].setColor(sf::Color::Black);
	Lifefuel[0].setString("3");
	Lifefuel[0].setScale(1.5, 1.5);
	Lifefuel[0].setPosition(sf::Vector2f(width-1346.0f, height - 738.0f));

	Lifefuel[1].setFont(font);
	Lifefuel[1].setColor(sf::Color::Black);
	Lifefuel[1].setString("10");
	Lifefuel[1].setScale(1.5, 1.5);
	Lifefuel[1].setPosition(sf::Vector2f(width - 66.0f, height - 738.0f));

}


LifeFuel::~LifeFuel()
{
}

void LifeFuel::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Lifefuel[i]);
	}
}


