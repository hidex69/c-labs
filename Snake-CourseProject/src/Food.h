// Food.h

#pragma once
#include "SFML/Graphics.hpp"

class Food
{
private:
	sf::CircleShape food;
	float x_food, y_food;
public:
	Food();
	void draw(sf::RenderWindow*);
	sf::Vector2f getFoodPosition();
	void spawn(std::vector<sf::RectangleShape> &);
};