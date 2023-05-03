#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Player
{
private:

	//render
	sf::Texture texture;
	sf::Sprite sprite;


	float mouvementspeed;

	//private functions
	void initTexture();
	void initSprite();




public:
	//destr constr
	Player();
	virtual ~Player();

	//functions
	void move(const float dirx, const float diry);
	void update();
	void render(sf::RenderTarget& target);
};

