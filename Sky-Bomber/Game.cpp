#include "../GameEngine.h"
#include "../MainMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../splashscreen.h"
#include <SFML/Audio.hpp>
#include "../HighScoreScreen.h"


void Game::start(){

	sf::Music bgmusic;
	sf::SoundBuffer enter, selecting;
	sf::Sound entersound, selectingsound;

	if (!bgmusic.openFromFile("resources/mainmenu.wav"))
		std::cout << "Cannot Stream the Music" << std::endl;
	if (!enter.loadFromFile("resources/entering.wav"))
		std::cout << "Cannot Open File" << std::endl;
	if (!selecting.loadFromFile("resources/buttonpress.wav"))
		std::cout << "can't find sound" << std::endl;

	//Setting Buffer
	entersound.setBuffer(enter);
	selectingsound.setBuffer(selecting);
	
	//Rendering Window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Sky Bomber");
	bgmusic.play();			//Background Music

	sf::Texture mainmenu;
	if (!mainmenu.loadFromFile("resources/splash.png"))		
		std::cout << "Load failed" << std::endl;

	sf::Sprite mainscreensprite;
	mainscreensprite.setTexture(mainmenu);

	//Menu Main Content
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
								menu.MoveUp();
								break;

								case sf::Keyboard::Down:
								selectingsound.play();
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
										window.close();
										Screen::HighScore();
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
