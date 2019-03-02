#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Tank
{
    private:
		sf::Sprite tankSprite;
		sf::Texture tankTexture;
	public:
		Tank();
		Tank(sf::Texture&);
		float x, y;
		float offsetX;
		void setTexture(sf::Texture&);
		void setPosition(sf::Vector2f);
		sf::Vector2f getPosition();
		sf::Sprite& getAddress();
		void setScale(sf::Vector2f);
		void draw(sf::RenderWindow&);

		
    
};