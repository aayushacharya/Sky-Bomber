
#pragma once
#include<SFML/Graphics.hpp>

class FuelCheck {
public:
	  int currentFuel;
	  FuelCheck()
	  {
		 
	  }
	bool isFinished(bool collision = false);
	void setFuel(int ccurrentFuel)
	{
		currentFuel = ccurrentFuel;
	}
	int getFuel()
	{
		return currentFuel;
	}
};
