//Game.h

#pragma once
#include "Food.h"
#include "Snake.h"

class Game : public Snake, public Food
{
private:
	double time, timer, delay;

	sf::Font f;
	sf::Text t;


	sf::RenderWindow* win;
	sf::Clock clock;
	sf::Event event;
public:
	Game();
	void gameAction(sf::Sprite &);
};