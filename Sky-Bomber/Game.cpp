#include "../GameEngine.h"
#include "../MainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../splashscreen.h"
#include <SFML/Audio.hpp>


void Game::start(){

	sf::Music bgmusic;

	if (!bgmusic.openFromFile("resources/mainmenu.wav"))
		std::cout << "Cannot Load" << std::endl;

	bgmusic.setVolume(20.0f);
	sf::SoundBuffer enter, selecting;
	sf::Sound entersound, selectingsound;

	if (!enter.loadFromFile("resources/entering.wav"))
		std::cout << "can't find sound" << std::endl;
	entersound.setBuffer(enter);

	if (!selecting.loadFromFile("resources/buttonpress.wav"))
		std::cout << "can't find sound" << std::endl;
	selectingsound.setBuffer(selecting);
	

sf::RenderWindow window(sf::VideoMode(1366, 768), "Sky Bomber");
sf::Texture mainmenu;
bgmusic.play();
if (!mainmenu.loadFromFile("resources/splash.png"))
{
	std::cout << "Load failed" << std::endl;
	//system("pause");
}
sf::Sprite mainscreensprite;
mainscreensprite.setTexture(mainmenu);

Menu menu(window.getSize().x, window.getSize().y);

while (window.isOpen())
{
	sf::Event event;

	while (window.pollEvent(event))
	{

		switch (event.type)
		{
			
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				selectingsound.play();
			//	Manager::menuselectsound();
				menu.MoveUp();
				break;

			case sf::Keyboard::Down:
				//menubuttonsound.play();
				selectingsound.play();
				//Manager::enter();
				menu.MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (menu.GetPressedItem())
				{
				case 0:
					window.close();
					entersound.play();
					bgmusic.pause();
					Engine::start();

					std::cout << "Play button has been pressed" << std::endl;
					break;
				case 1:
					//enter.play();
					std::cout << "HighScore should be displayed" << std::endl;
					break;
				case 2:
					//enter.play();
					std::cout << "Game Exit" << std::endl;
					window.close();
					break;
				}

				break;
			}

			break;
		case sf::Event::Closed:
			window.close();

			break;

		}
	}

	window.clear();
	
	window.draw(mainscreensprite);
	menu.draw(window);

	window.display();
}
}
