#pragma once
#include <SFML/Graphics.hpp>

class Unit
{

private:
	// text
	sf::Texture texture;
	sf::Sprite sprite;
	//game variable
	int side;
	int hp;
	int damage;
	float mouvementspeed;
	float directionx;
	float directiony;
	int state;
	
	sf::Time elapsed; 

	//private function
	void initUnit();
	void initTexture();
	void initSprite();

	

public:
	//constru destr
	Unit(int side, float posx, float posy,float dirx, float diry);
	virtual ~Unit();

	//accessor
	const sf::FloatRect getbounds() const;
	 

	//functions

	void change_direction(const float dirx, const float diry);
	void change_state(int st);
	void move();
	bool get_time(sf::Time);
	void reverse();
	void update(std::vector<Unit*> units);
	void render(sf::RenderTarget& target);


};

