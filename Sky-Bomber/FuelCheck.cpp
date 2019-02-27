#include"../FuelCheck.h"
#include<SFML/Graphics.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
bool FuelCheck::isFinished(bool collision)
{
	static sf::Clock clk;
	static int startFuel = 30;
	static bool fuelFinished = false;
	if (clk.getElapsedTime().asSeconds() > 10.0f)
	{
		
		
			startFuel -= 10;
		


		if (startFuel == 0)
		{
			fuelFinished = true;
		}
		return fuelFinished;
		clk.restart();
	}
	if (collision)
	{
		if (startFuel < 30)
		{
			startFuel += 10;
		}
		else
		{
			startFuel = 30;
		}
		clk.restart();

	}
	return fuelFinished;
}