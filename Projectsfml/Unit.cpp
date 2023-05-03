#include "Unit.h"
#include <iostream>


void Unit::initUnit()
{
	this->damage = 1;
	this->hp = 10;
	this->mouvementspeed = 0.5f;
	this->state = 0;
	this->elapsed = sf::seconds(0.f);

}

void Unit::initTexture()
{
	switch(this->side)
	{ 
		case 1: //blue soldier
			this->texture.loadFromFile("textures/blue-inf.png");
			if (!this->texture.loadFromFile("textures/blue-inf.png"))
			{
				std::cout << "ERROR::UNIT::BLUETEXT" << "\n";
			}
			break;
		case 2: //red soldier
			this->texture.loadFromFile("textures/red-inf.png");
			if (!this->texture.loadFromFile("textures/red-inf.png"))
			{
				std::cout << "ERROR::UNIT::REDTEXT" << "\n";
			}
			break;
	}
}

void Unit::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.05f, 0.05f);

}



Unit::Unit(int side, float posx, float posy,float dirx, float diry)
{
	this->side = side;
	this->initUnit();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(posx, posy);

	this->directionx = dirx;
	this->directiony = diry;
}


Unit::~Unit()
{
}

const sf::FloatRect Unit::getbounds() const
{
	return this->sprite.getGlobalBounds();
}


void Unit::move()
{
	this->sprite.move(this->mouvementspeed * (-this->directionx), this->mouvementspeed * (-this->directionx));
	
}
bool Unit::get_time(sf::Time chrono)
{
if((chrono - this->elapsed) > sf::seconds(10.f))
{
	this->elapsed = chrono;
	return true;
}
else
	return false;
}
void Unit::change_direction(const float dirx, const float diry)
{
	this->directionx = dirx;
	this->directiony = diry;
}

void Unit::change_state(int st)
{
	this->state = st;
}
void Unit::reverse()
{
	this->change_direction(-directionx,-directiony);
}


void Unit::update(std::vector<Unit*> units)
{


}

void Unit::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


