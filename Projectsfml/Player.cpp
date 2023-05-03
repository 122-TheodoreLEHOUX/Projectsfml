#include "Player.h"
#include <iostream>

void Player::initTexture()
{
	//load texture
	this->texture.loadFromFile("textures/etendard.png");
	if (!this->texture.loadFromFile("textures/etendard.png"))
	{ 
		std::cout << "ERROR::PLAYER::texture"<< "\n";
	}
}

void Player::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.05f,0.05f);
}

Player::Player()
{
	this->mouvementspeed = 10.f;
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::move(const float dirx, const float diry)
{
	this->sprite.move(this->mouvementspeed * dirx, this->mouvementspeed * diry);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
