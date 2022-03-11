#pragma once
#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#include "SFML/Graphics.hpp"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 2

class LifeFuel
{
public:
	LifeFuel(float width, float height, int fuel, int life);
	~LifeFuel();

	void draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text Lifefuel[MAX_NUMBER_OF_ITEMS];

};

