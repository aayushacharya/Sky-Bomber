#include "../GameEngine.h"
#include "../MainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "splashscreen.h"
#include <SFML/Audio.hpp>
using namespace std;

void Splash::start() {
	
	sf::Music bgmusic;
	//sound for intro or splashscreen music
	if (!bgmusic.openFromFile("resources/intro.wav"))
		std::cout << "Cannot Load" << std::endl;


	sf::RenderWindow window(sf::VideoMode(1366, 768), "Sky Bomber");
	sf::Texture splash1, splash2;
	bgmusic.play();
	bgmusic.setVolume(10.f);
	//first picture in splash
	if (!splash1.loadFromFile("resources/splash1.png"))
	{
		std::cout << "Load Failed" << std::endl;
	}
	//second picture in splash
	if (!splash2.loadFromFile("resources/splash2.png"))
	{
		std::cout << "load failed" << std::endl;
	}

	//giving texture to sprites
	sf::Sprite splash1sprite, splash2sprite;
	splash1sprite.setTexture(splash1);
	splash2sprite.setTexture(splash2);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//for splash1
		window.clear();
		window.draw(splash1sprite);
		window.display();
		Sleep(3000);
		//for splash2
		window.clear();
		window.draw(splash2sprite);
		window.display();
		Sleep(3000);
		bgmusic.pause();
		window.close();
	}
	//after the splash terminate or works well the main screen fuction called
	Game::start();
}
