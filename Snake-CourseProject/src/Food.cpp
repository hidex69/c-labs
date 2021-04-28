// Food.cpp

#include "Food.h"
#include <random>

Food::Food() {
	food.setRadius(15);
	x_food = 330, y_food = 330;
	food.setFillColor(sf::Color::Red);
	food.setPosition(x_food, y_food);
}

void Food::draw(sf::RenderWindow *win) {
	win->draw(food);
}

sf::Vector2f Food::getFoodPosition() {
	return food.getPosition();
}

void Food::spawn(std::vector<sf::RectangleShape> &body) {
	
	bool isEnd = false;

	do {
		x_food = (rand() % 19) * 30;
		y_food = (rand() % 19) * 30;
		food.setPosition(x_food, y_food);
		for (auto i : body) {
			if (i.getPosition() == food.getPosition()) {
				isEnd = false;
			}
			else isEnd = true;
		}

	} while (!isEnd);
}