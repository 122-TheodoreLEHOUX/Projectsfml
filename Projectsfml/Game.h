#pragma once
#include "Player.h"
#include "Unit.h"

using namespace std;

class Game
{
private:
	//variables window
	sf::RenderWindow* Window;
	sf::Image logo;
	sf::FloatRect* borderN;
	sf::FloatRect* borderS;
	sf::FloatRect* borderW;
	sf::FloatRect* borderE;
	Player* player;
	Unit* unit;
	std::vector<Unit*> units;

	sf::Clock clock;

	int bluenumber;
	int rednumber;

	//GUI
	sf::Font font;
	sf::Text scoretext;

	//background
	sf::Texture backgroundtexture;
	sf::Sprite background;

	//functions
	void initWindow();
	void initPlayer();
	void initUnit();
	void initGUI();
	void initBackground();


public:


	Game();
	virtual ~Game();

	//functions
	void updateUnits();
	void renderbackground();
	void run();
	void update();
	void render();




};

