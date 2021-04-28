//Menu.cpp

#include "Menu.h"

Menu::Menu() {

	win = new sf::RenderWindow(sf::VideoMode(600, 600), "Snake");
	font.loadFromFile("img/font.ttf");
	win->setFramerateLimit(60);

	text.setFont(font);
	text.setCharacterSize(80);
	text.setFillColor(sf::Color::Green);

	texture.loadFromFile("img/back.jpg");
	background.setTexture(texture);


	for (int i = 0; i < 3; i++) {
		menuText.push_back(text);
		menuText[i].setPosition(180, i * 150 + 50);
	}

	menuText[0].setString("PLAY");
	menuText[1].setString("ABOUT");
	menuText[2].setString("EXIT");

	selected = 0;

}

sf::RenderWindow* Menu::getWindow()
{
	return win;
}

void Menu::selectedItem() {
	for (int i = 0; i < 3; i++) {
		menuText[i].setFillColor(sf::Color::Green);
	}
	menuText[selected].setFillColor(sf::Color::Red);
}

void Menu::draw() {
	for (int i = 0; i < 3; i++) {
		win->draw(menuText[i]);
	}
}

void Menu::show() {

	sf::Event event;
	while (win->isOpen()) {
		while (win->pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter && selected == 0) {
					Game game;
					game.gameAction(background);
					
				}
				else if (event.key.code == sf::Keyboard::Enter && selected == 2) {
					win->close();
				}
				else if (event.key.code == sf::Keyboard::Enter && selected == 1) {
					AboutWindow aboutWindow;
					aboutWindow.show(win, background);
				}
			}
			switch (event.type)
			{
			case sf::Event::Closed:
				win->close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Down:
					if (selected < 2) {
						selected++;
					}
					else if (selected == 2) {
						selected = 0;
					}
					break;
				case sf::Keyboard::Up:
					if (selected > 0) {
						selected--;
					}
					else if (selected == 0) {
						selected = 2;
					}
					break;
				}
				break;
			}
		}
		this->selectedItem();

		win->clear();
		win->draw(background);
		this->draw();
		win->display();

	}
}