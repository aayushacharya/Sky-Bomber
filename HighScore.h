#pragma once
#include <fstream>
#include<iostream>
namespace Highscore
{
	void Save(int score);
	void Get(std::string getName[3],std::string getHighScore[3]);
}