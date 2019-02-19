#include "../GameEngine.h"
#include "../MainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../splashscreen.h"


void Game::start(){

sf::RenderWindow window(sf::VideoMode(1366, 768), "Sky Bomber", sf::Style::Fullscreen);
sf::Texture mainmenu;
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
				menu.MoveUp();
				break;

			case sf::Keyboard::Down:
				menu.MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (menu.GetPressedItem())
				{
				case 0:
					window.close();
					Engine::start();

					std::cout << "Play button has been pressed" << std::endl;
					break;
				case 1:
					std::cout << "HighScore should be displayed" << std::endl;
					break;
				case 2:
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




