#include "../HighScore.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
void Highscore::Save(int score)
{
	ifstream readFile;
	readFile.open("highscore.txt");
	string line[4];
	string getLine[3];
	string highscore[3];
	int getHighScore[3];
	int hscore[4];
	int flag = 0;
	string Newname;
	for (int i = 0;i < 3;i++)
	{
		getline(readFile, getLine[i]);
		getline(readFile, highscore[i]);
		getHighScore[i] = stoi(highscore[i]);
		if (score > getHighScore[i])
		{
			line[i + 1] = getLine[i];
			if (!flag)
			{
				std::cout << "Enter your name: ";
				std::cin >> Newname;
				line[i] = Newname;
				hscore[i] = score;
			}
			hscore[i + 1] = getHighScore[i];
			flag = 1;
		}
		else {
			line[i] = getLine[i];
			hscore[i] = getHighScore[i];
		}
	}
	readFile.close();
	ofstream writeFile("highscore.txt");


	for (int i = 0;i < 3;i++)
	{
		std::string putName = line[i] + "\n";
		std::string putScore = to_string(hscore[i]) + "\n";
		writeFile << putName;
		writeFile << putScore;
	}
	writeFile.close();
}

void Highscore::Get(std::string getName[3],std::string getHighScore[3])
{
	ifstream readfile;
	readfile.open("highscore.txt");
	for (int i = 0;i < 3;i++)
	{
		getline(readfile, getName[i]);
		getline(readfile, getHighScore[i]);
	}
	readfile.close();
}