//GameOverMessage.h

#include "GameOverMessage.h"

GameOverMessage::GameOverMessage()
{

	font.loadFromFile("img/font.ttf");

	text.setFont(font);

	textMenu.push_back(text);
	textMenu.push_back(text);
	textMenu.push_back(text);

	textMenu[0].setString("GAME OVER");
	textMenu[0].setPosition(sf::Vector2f(38, 30));
	textMenu[0].setCharacterSize(100);
	textMenu[0].setFillColor(sf::Color::Yellow);

	textMenu[1].setString("Press 'Enter' to exit");
	textMenu[1].setPosition(sf::Vector2f(145, 200));
	textMenu[1].setCharacterSize(30);
	textMenu[1].setFillColor(sf::Color::Yellow);

	textMenu[2].setString("NEW RECORD!!!");
	textMenu[2].setPosition(sf::Vector2f(34, 300));
	textMenu[2].setCharacterSize(80);
	textMenu[2].setFillColor(sf::Color::Blue);
}

void GameOverMessage::show(sf::RenderWindow *win, sf::Sprite &background, bool newRecord)
{
	sf::Event event;
	while (win->isOpen()) {

		while (win->pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter) {
					win->close();
				}
			}
		}

		win->clear();
		win->draw(background);
		win->draw(textMenu[0]);
		win->draw(textMenu[1]);
		if(newRecord) {
			win->draw(textMenu[2]);
		}
		win->display();
	}
}
