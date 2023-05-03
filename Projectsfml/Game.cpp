#include "Game.h"
using namespace std;

//private functions
void Game::initWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode(800, 600), "Kings&Generals", sf::Style::Close | sf::Style::Titlebar);
	this->Window->setFramerateLimit(60);
	this->Window->setVerticalSyncEnabled(false);
	//set icon to the window
	//this->logo.LoadFrom("textures.logo"); // File/Image/Pixel
	//this->Window.SetIcon();

}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initUnit()
{
	//nombre de soldats
	this->rednumber = 2;
	this->bluenumber = 0;
	//tant que le nombre n'est pas atteint génere un soldat à une position aléatoire 
	for (int i = 0; i < this->rednumber; i++)
	{
		//this->units.push_back(new Unit(2, static_cast<float>(rand() % 800 + 1), static_cast<float>(rand() % 20 + 1)));
		this->units.push_back(new Unit(2, static_cast<float>(rand() % 800 + 1), static_cast<float>(rand() % 400 + 100), static_cast<float>(rand() % 3 +(-1)), static_cast<float>(rand() % 3  +(-1))));

	}
	for (int i = 0; i < this->bluenumber; i++)	
	{
		this->units.push_back(new Unit(1, 200.f, 500.f, static_cast<float>(rand() % 3 + (-1)), static_cast<float>(rand() % 3 +(-1))));
		//this->units.push_back(new Unit(1, static_cast<float>(rand() % 800 + 1), static_cast<float>(rand() % 50 + 550)));
	}
}

void Game::initGUI()
{
}

void Game::initBackground()
{
	this->backgroundtexture.loadFromFile("map/map.png");
	if (!this->backgroundtexture.loadFromFile("map/map.jpg"))
	{
		std::cout << "ERROR::MAP::texture" << "\n";
	}
	this->background.setTexture(this->backgroundtexture);
	this->background.setScale(2.f, 2.f);
}

//constructor destructor

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initUnit();
	this->initBackground();
	this->borderN = new sf::FloatRect(0, -10, 800, 10);
	this->borderS = new sf::FloatRect(0, 600, 800, 10);
	this->borderW = new sf::FloatRect(-10, 0, 10, 600);
	this->borderE = new sf::FloatRect(800, 0, 10, 600);
}

Game::~Game()
{
	delete this->Window;
	delete this->player;
	for (auto *i : this->units)
	{
		delete i;
	}
}


//public functions

void Game::updateUnits()
{
	for (int i = 0; i < this->units.size(); i++)
	{
		std::cout << i;
		units[i]->move();
		//collision with borders
		if (units[i]->getbounds().intersects(*this->borderN) || units[i]->getbounds().intersects(*this->borderS) || units[i]->getbounds().intersects(*this->borderW) || units[i]->getbounds().intersects(*this->borderE))
			{
				units[i]->reverse();
				units[i]->move();
				printf("reverse \n");
			}
		if (units[i]->get_time(clock.getElapsedTime()))
			{
				printf("change \n");
				units[i]->change_direction(static_cast<float>(rand() % 3 + +(-1)), static_cast<float>(rand() % 3 + (-1)));
				units[i]->move();
			}
	
		
	}
}

void Game::renderbackground()
{
	this->Window->draw(this->background);
}


void Game::run()
{
	while (this->Window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	sf::Event e;
	while (this->Window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->Window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->Window->close();
		}
	}
	//move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);

	//units management

		this->updateUnits();

	
}

void Game::render()
{
	this->Window->clear();
	//draw here
	//background
	this->renderbackground();
	//player
	this->player->render(*this->Window);
	//unit
	for (auto* unit : this->units)
	{
		unit->render(*this->Window);
	}
	this->Window->display();
}
