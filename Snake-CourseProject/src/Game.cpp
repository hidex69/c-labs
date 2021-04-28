//Game.cpp

#include "Game.h"
#include <iostream>

Game::Game() {
	win = new sf::RenderWindow(sf::VideoMode(600, 600), "Snake");
	
	f.loadFromFile("img/font.ttf");
	t.setFont(f);
	t.setCharacterSize(25);
	t.setPosition(sf::Vector2f(10, 0));
	t.setFillColor(sf::Color::Blue);


	timer = 0;
	delay = 0.1;
	win->setFramerateLimit(60);
}

void Game::gameAction(sf::Sprite &background) {
	Snake snake;
	Food food;
	
	std::ifstream fin;
	fin.open("Record.txt", std::ios::in);

	std::string str;
	fin >> str;
	fin.close();

	while (win->isOpen()) {
		time = clock.getElapsedTime().asSeconds();
		timer += time;
		clock.restart();

		t.setString(snake.getScore() + '\n' + "High score: " + str);

		while (win->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win->close();
			}
			if (event.type == sf::Event::KeyPressed) {
				snake.controller(event);
			}
		}
		

		if (timer > delay) {
			if (snake.getCurrentPos() == food.getFoodPosition()) {
				snake.eat();
				food.spawn(snake.getBody());
				std::cout << snake.getScore() << std::endl;
			}
			snake.move();
			snake.isCrashed(win, background);
			timer = 0;
		}


		win->clear();
		win->draw(background);
		food.draw(win);
		snake.draw(win);
		win->draw(t);
		win->display();
	}
}