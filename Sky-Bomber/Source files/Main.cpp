#include "../GameEngine.h"
#include "../MainMenu.h"
#include <iostream>
#include "../splashscreen.h"
using namespace std;

int main()
{
	std::cout << "Sky Bomber \
                 \n\nProject On OOP \
                 \n\nBy : Aayush Acharya 074BCT501 \
                 \n     Anjil Bishowkarma 074BCT505 \
                 \n     Nirajan Basnet 074BCT522 " << endl;
	Splash::start();
	Game::start();
}