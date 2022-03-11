#pragma once
#include<SFML/Graphics.hpp>

class FuelCheck {
public:
	int currentFuel;
	int currentLife;

	FuelCheck()
	{

	}
	bool isFinished(bool collision = false);
	void setFuel(int ccurrentFuel )
	{
		currentFuel = ccurrentFuel;
	}
	int getFuel()
	{
		return currentFuel;
	}
	void setLife(int ccurrentLife)
	{
		currentLife = ccurrentLife;
	}
	int getLife()
	{
		return currentLife;
	}
};
