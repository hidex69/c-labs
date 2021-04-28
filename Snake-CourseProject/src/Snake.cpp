//Snake.cpp

#include "Snake.h"
#include <iostream>

Snake::Snake() {
	rect.setSize(sf::Vector2f(30.0, 30.0));
	rect.setFillColor(sf::Color::Green);
	x = 120.0;
	y = 120.0;
	size = 4;
	score = 0;
	for (int i = 0; i < size; i++) {
		body.push_back(rect);
	}
	body[0].setPosition(120, 120);
	body[0].setFillColor(sf::Color::White);
	for (int i = 1; i < size; i++) {
		body[i].setPosition(120 - i * 30, 120);
	}
	dir = 1;
}

void Snake::draw(sf::RenderWindow* win) {
	for (int i = 0; i < size; i++) {
		win->draw(body[i]);
	}
}

void Snake::move() {
	sf::Vector2f position1 = body[0].getPosition(), position2;
	switch (dir) {
	case 1: {
		for (int i = 1; i < size; i++) {
			position2 = body[i].getPosition();
			body[i].setPosition(position1);
			position1 = position2;
		}
		body[0].move(30, 0);
		break;
	}
	case 2: {
		for (int i = 1; i < size; i++) {
			position2 = body[i].getPosition();
			body[i].setPosition(position1);
			position1 = position2;
		}
		body[0].move(-30.0, 0);
		break;
	}
	case 3: {
		for (int i = 1; i < size; i++) {
			position2 = body[i].getPosition();
			body[i].setPosition(position1);
			position1 = position2;
		}
		body[0].move(0, 30.0);
		break;
	}
	case 4: {
		for (int i = 1; i < size; i++) {
			position2 = body[i].getPosition();
			body[i].setPosition(position1);
			position1 = position2;
		}
		body[0].move(0, -30.0);
		break;
	}
	}
}

void Snake::controller(sf::Event ev) {
	if (ev.key.code == sf::Keyboard::Right && dir != 2) {
		dir = 1;
	}
	if (ev.key.code == sf::Keyboard::Left && dir != 1) {
		dir = 2;
	}
	if (ev.key.code == sf::Keyboard::Down && dir != 4) {
		dir = 3;
	}
	if (ev.key.code == sf::Keyboard::Up && dir != 3) {
		dir = 4;
	}
}

sf::Vector2f Snake::getCurrentPos() {
	return body[0].getPosition();
}

void Snake::eat() {
	score++;
	size++;
	body.push_back(rect);
	body[size - 1].setPosition(body[size - 2].getPosition());
}

int Snake::getSize() {
	return size;
}

void Snake::isCrashed(sf::RenderWindow *win, sf::Sprite &background) {
	for (int i = 1; i < size; i++) {
		bool newRecord = false;
		if (body[0].getPosition() == body[i].getPosition() || body[0].getPosition().x < 0 || body[0].getPosition().x > 570 ||
			body[0].getPosition().y < 0 || body[0].getPosition().y > 570) {

			if (body[0].getPosition() == body[i].getPosition()) {
				std::cerr << "Exception. You crashed into yourself\n";
			}
			else {
				std::cerr << "Exception. You crashed at the end of the playing ground\n";
			}

			std::ifstream fin;
			fin.open("Record.txt", std::ios::in);
			int prevScore;
			fin >> prevScore;
			if (prevScore < score) {
				fin.close();
				std::ofstream fout;
				fout.open("Record.txt", std::ios::out);
				newRecord = true;
				fout << score;
				fout.close();
			}

			GameOverMessage gameOver;
			gameOver.show(win, background, newRecord);
			
		}
	}
}

std::string Snake::getScore() {
	return "Score: " + std::to_string(score);
}

int Snake::getScoreInt() {
	return score;
}

std::vector<sf::RectangleShape>& Snake::getBody()
{
	return body;
}
