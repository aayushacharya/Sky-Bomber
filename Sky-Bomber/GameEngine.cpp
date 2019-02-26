#include "../GameEngine.h"
#include "../Missile.h"
#include "../Collision.h"
#include "SFML/Audio.hpp"
#include "Explosion.h"
void Engine::start() {
	//inital parameters set
	float planeX = 40.0f, planeY = 80.0f;
	/*float *Xplane,*Yplane,*planeXOffset, *planeYOffset;
	float upRotate, downRotate;*/
	float truckX = 700.0f, truckY = 680.0f;
	float tankX = 30.0f, tankY = 680.0f;
	float planeOffsetX = 5.0f, truckOffsetX = 3.0f;
	float tankOffsetX = 4.0f;
	float planeOffsetY = 5.0f;
	float missileX = planeX, missileY = planeY;
	float missileOffsetX = planeOffsetX, missileOffsetY = planeOffsetX;
	float truck_CollisionX, truck_CollisionY;
	float tank_CollisionX, tank_CollisionY;
	bool missileLaunched = false;
	bool truckCollision = false;
	bool tankCollision = false;
	std::string planePosition = "right";
	//clock for updating game loop
	sf::Clock clk;
	sf::Clock animationTime;
	sf::Clock explosionTime;
	sf::Music launching, ingamemusic, planesound, explosion;



	if (!launching.openFromFile("resources/Missilelunched.wav"))
		std::cout << "can't find sound" << std::endl;
	if (!planesound.openFromFile("resources/planesound.wav"))
		std::cout << "can't find sound" << std::endl;

	if (!ingamemusic.openFromFile("resources/ingame.wav"))
		std::cout << "not working" << std::endl;
	if (!explosion.openFromFile("resources/Explosion.wav"))
		std::cout << "sound not streamed" << std::endl;

	ingamemusic.setVolume(10.0f);

	//window event
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SKY BOMBER");
	//application icon doesnot work code is below
	/*sf::Image icon;
	icon.loadFromFile("resources/plane3.png"); // File/Image/Pixel
	window.setIcon(30,30);	*/
	window.setFramerateLimit(60);

	ingamemusic.play();
	planesound.play();
	//texture and sprites for loading images
	sf::Texture bgtexture, planeTexture; //groundTexture, grassTexture, stoneTexture;
	sf::Texture mTruckTexture, tankTexture, missileTexture;
	if (!bgtexture.loadFromFile("resources/background.png")) //|| !groundTexture.loadFromFile("resources/ground.png")
		std::cout << "Cannot load from file";
	//	if (!grassTexture.loadFromFile("resources/grass.png") || !stoneTexture.loadFromFile("resources/stone.png"))
		//	std::cout << "Cannot open from file";
	if (!planeTexture.loadFromFile("resources/plane1.png") || !missileTexture.loadFromFile("resources/missile.png"))
		std::cout << "Cannot open from file";
	if (!mTruckTexture.loadFromFile("resources/mtruck.png") || !tankTexture.loadFromFile("resources/tank.png"))
		std::cout << "Cannot load from file";
	sf::Sprite bgsprite, planeSprite, mTruckSprite; //, groundSprite, grassSprite, stoneSprite
	sf::Sprite tankSprite, missileSprite;
	mTruckSprite.setTexture(mTruckTexture);
	bgsprite.setTexture(bgtexture);
	planeSprite.setTexture(planeTexture);
	tankSprite.setTexture(tankTexture);
	missileSprite.setTexture(missileTexture);

	sf::Vector2u sizemTruck = mTruckTexture.getSize();
	sf::Vector2u sizeTank = tankTexture.getSize();

	//Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color::Black);
		//background drawn
		window.draw(bgsprite);
		float screenX = 0.0f, screenY = 600.0f;

		missileSprite.setPosition(sf::Vector2f(missileX, missileY));
		planeSprite.setPosition(sf::Vector2f(planeX, planeY));
		mTruckSprite.setPosition(sf::Vector2f(truckX, truckY - sizemTruck.y));
		tankSprite.setPosition(sf::Vector2f(tankX, tankY - sizeTank.y + 5.0f));



		//todo plane conditions
		//plane boundary conditions
		if (planeX < 0)
		{
			planeSprite.setScale(sf::Vector2f(1.0f, 1.0f));
			missileSprite.setScale(sf::Vector2f(1.0f, 1.0f));
			planePosition = "right";
			planeOffsetX = fabsf(planeOffsetX);
			missileOffsetX = fabsf(missileOffsetX);
		}
		if (planeX > 1360)
		{
			planeSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
			missileSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
			planePosition = "left";
			planeOffsetX = -fabsf(planeOffsetX);
			missileOffsetX = -fabsf(missileOffsetX);
		}
		if (planeY > (screenY - 180.0f))
		{
			planeSprite.setRotation(270.0f);
			missileSprite.setRotation(270.0f);
			//planeOffsetY = -fabsf(planeOffsetY);
		}
		if (planeY < 0)
		{
			planeSprite.setRotation(90.0f);
			missileSprite.setRotation(90.0f);
			//planeOffsetY = fabsf(planeOffsetY);
		}
		//truck boundary conditions
		if (truckX < 0)
		{
			mTruckSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
			truckOffsetX = -fabsf(truckOffsetX);
		}
		if (truckX > 1360)
		{
			mTruckSprite.setScale(sf::Vector2f(1.0f, 1.0f));
			truckOffsetX = fabsf(truckOffsetX);
		}
		//tank boundary conditions
		if (tankX < 0)
		{
			tankSprite.setScale(sf::Vector2f(1.0f, 1.0f));
			tankOffsetX = fabsf(tankOffsetX);
		}
		if (tankX > 1360)
		{
			tankSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
			tankOffsetX = -fabsf(tankOffsetX);
		}
		//when down key is pressed 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			planeSprite.rotate(-3.0f);
			missileSprite.rotate(-3.0f);


			/*planeSprite.setRotation(0.0f);
			planeSprite.setScale(sf::Vector2f(-1.0f, 1.0f));
			if (planeOffsetX > 0)
			{
				planeOffsetX = -planeOffsetX;
			}
			plane = &planeX;
			planeOffset = &planeOffsetX;*/

		}
		//when up arrow key is pressed 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			planeSprite.rotate(3.0f);
			missileSprite.rotate(3.0f);
			/*planeSprite.setRotation(0.0f);
			planeSprite.setScale(sf::Vector2f(1.0f, 1.0f));
			planeOffsetX = fabsf(planeOffsetX);*/
		}
		//whe escape is pressed game wil be exited
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{

			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			ingamemusic.pause();
			planesound.pause();
			window.close();
			Game::start();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			launching.play();
			missileLaunched = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			planesound.pause();
			window.close();
			Engine::start();
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			//if planeOffsetX is negative then -90
			upRotate = planeSprite.getRotation();
			if ((int)upRotate < 270)
			{
				if ((int)upRotate > 265)
				{
					upRotate = 270.0f;
					upRotate = planeSprite.getRotation();
				}
				else
				{
				planeSprite.rotate(0.5f);
				upRotate = planeSprite.getRotation();
				}
			}
			if ((int)upRotate > 270)
			{
				if ((int)upRotate < 275)
				{
					upRotate = 270.0f;
					upRotate = planeSprite.getRotation();
				}
				else {
					planeSprite.rotate(-0.5f);
					upRotate = planeSprite.getRotation();
				}
			}
			planeSprite.setRotation(upRotate);
			planeOffsetY = -fabsf(planeOffsetY);
			//todo from here
			plane = &planeY;
			planeOffset = &planeOffsetY;
		}*/
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			downRotate=planeSprite.getRotation();
			if ((int)downRotate < 90)
			{
				if ((int)downRotate > 85)
				{
					downRotate = 90.0f;
					downRotate = planeSprite.getRotation();
				}
				else {
					planeSprite.rotate(0.5f);
					downRotate = planeSprite.getRotation();
				}
			}
			if ((int)downRotate > 90)
			{
				if ((int)downRotate < 95)
				{
					downRotate = 90.0f;
					downRotate = planeSprite.getRotation();
				}
				else {
					planeSprite.rotate(-0.5f);
					downRotate = planeSprite.getRotation();
				}
			}
			planeSprite.setRotation(downRotate);
			planeOffsetY = fabsf(planeOffsetY);
			//todo
			plane = &planeY;
			planeOffset = &planeOffsetY;
		}*/

		//see for boundary condition
		//trying to do for velocity and failing miserably
		//planeOffsetX = cos(planeSprite.getRotation())*5.0f;
		//missileOffsetX = cos(missileSprite.getRotation())*5.0f;
		planeOffsetY = sin(planeSprite.getRotation())*5.0f;
		missileOffsetY = sin(missileSprite.getRotation())*5.0f;
		planeX += planeOffsetX;
		planeY += planeOffsetY;
		truckX = truckX - truckOffsetX;
		tankX = tankX + tankOffsetX;

		missileX += missileOffsetX;
		if (missileLaunched)
		{
			Missile::move(&missileSprite, &missileY, planePosition);
			window.draw(missileSprite);
		}
		if (!missileLaunched)
		{
			missileY += missileOffsetY;
		}
		if (missileY > tankY)
		{
			missileSprite.setRotation(planeSprite.getRotation());
			missileSprite.setPosition(missileX, missileY);

			missileY = planeY;
			missileLaunched = false;
		}
		//clk.restart();

	//draw all the gameobjects according to z-index
		window.draw(missileSprite);
		window.draw(planeSprite);

		if (Collision::Detect(&missileSprite, &mTruckSprite))
		{
			tankCollision = false;
			truck_CollisionX = truckX, truck_CollisionY = truckY;
			truckCollision = true;
			Explosion::Create(truck_CollisionX, truck_CollisionY, window, "truck");
			explosion.play();
			truckOffsetX = 0;
			truckX = -100;

		}
		if (truckCollision)
		{

			Explosion::Create(truck_CollisionX, truck_CollisionY, window, "truck");
			

		}
		if (!truckCollision)
		{
			window.draw(mTruckSprite);
		}
		if (Collision::Detect(&missileSprite, &tankSprite))
		{
			tank_CollisionX = tankX, tank_CollisionY = tankY;
			tankCollision = true;
			Explosion::Create(tank_CollisionX, tank_CollisionY, window, "tank");
			explosion.play();
			tankOffsetX = 0;
			tankX = -100;
			truckCollision = false;
		}
		if (tankCollision)
		{

			Explosion::Create(tank_CollisionX, tank_CollisionY, window, "tank");

		}
		if (!tankCollision)
		{
			window.draw(tankSprite);
		}
		window.display();


	}

}
