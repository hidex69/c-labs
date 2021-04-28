//Snake.h

#pragma once
#include "GameOverMessage.h"
#include "SFML/Graphics.hpp"
#include "Food.h"
#include <fstream>

class Snake
{
private:
	int score;
	sf::RectangleShape rect;
	int dir;
	float x, y;
	int size;
	std::vector<sf::RectangleShape> body;
public:
	Snake();
	void move();
	int getSize();
	void draw(sf::RenderWindow*);
	void controller(sf::Event ev);
	sf::Vector2f getCurrentPos();
	void eat();
	void isCrashed(sf::RenderWindow*, sf::Sprite &);
	std::string getScore();
	int getScoreInt();
	std::vector<sf::RectangleShape>& getBody();
};