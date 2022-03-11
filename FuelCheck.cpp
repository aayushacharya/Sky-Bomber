#include"../FuelCheck.h"
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
bool FuelCheck::isFinished(bool collision)
{
	static sf::Clock clk;
	static int previousTime = 0;
	static int startFuel = 100;
	static int lifes = 3;
	static bool fuelFinished = false;
	static float dt = 0.0f;
	dt += clk.getElapsedTime().asSeconds();
	std::cout << int(dt) << std::endl;

	if (int(dt) > 0 && int(dt) != previousTime)

	{
		if (int(dt) % 2 == 0) {
			startFuel -=2;
			std::cout << "Fuel Decreases";
		}


		if (startFuel == 0)
		{

			lifes--;
			startFuel = 100;
		}


	}
	previousTime = int(dt);

	if (collision)
	{
		if (startFuel < 100)
		{
			std::cout << "Fuel Increases";
			startFuel += 2;
		}
		else
		{
			startFuel = 100;
		}

		std::cout << "gg " << std::endl;

	}

	if (lifes == 0)
	{
		fuelFinished = true;
	}

	setFuel(startFuel);
	setLife(lifes);
	std::cout << "The value is :" << getFuel() << "\n";
	clk.restart();
	return fuelFinished;
}
