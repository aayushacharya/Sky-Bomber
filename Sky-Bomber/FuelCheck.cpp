#include"../FuelCheck.h"
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
bool FuelCheck::isFinished(bool collision )
{
	static sf::Clock clk;
	static int previousTime= 0;
	static int startFuel = 30;
	static bool fuelFinished = false;
	static float dt = 0.0f;
	dt += clk.getElapsedTime().asSeconds();
	std::cout << int(dt) << std::endl;

	if (int (dt) > 0 && int(dt)!=previousTime )

	{
		if (int(dt) % 10 == 0) {
			startFuel -= 10; 
			std::cout << "Fuel Decreases";
		}
		

        if (startFuel == 0)
		{
			fuelFinished = true;
		}
		

	}
	previousTime = int(dt);
	
	if (collision)
	{
		if (startFuel < 30)
		{
			std::cout << "Fuel Increases";
			startFuel += 10;
		}
		else
		{
			startFuel = 30;
		}
		
		std::cout << "Mothersndsjhdjshdjjshdjshdjhsjhdjshdjhsd " << std::endl;

	}
	setFuel(startFuel);
	std::cout << "The value is :" <<getFuel() << "\n";
	clk.restart();
	return fuelFinished;
}
