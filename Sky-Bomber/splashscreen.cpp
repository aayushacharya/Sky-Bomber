#include "../GameEngine.h"
#include "../MainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "splashscreen.h"
using namespace std;

void Splash::start() {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Sky Bomber");
	sf::Texture splash;
	if (!splash.loadFromFile("resources/splashscreen.png"))
	{
		std::cout << "Load Failed" << std::endl;
	}
	sf::Sprite splashsprite;
	splashsprite.setTexture(splash);


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		window.draw(splashsprite);
		window.display();
		Sleep(5000);
		window.close();
	}
}
