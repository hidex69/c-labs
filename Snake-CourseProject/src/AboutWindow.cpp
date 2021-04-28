// AboutWindow.h

#include "AboutWindow.h"

AboutWindow::AboutWindow() {
	
	font.loadFromFile("img/font.ttf");

	str = "        It is the snake game\n'Left', 'Right', 'Up' and 'Down'\n buttons to change direction\nPress 'Enter' to back to menu";


	text.setFont(font);
	text.setFillColor(sf::Color::Blue);
	text.setString(str);
	text.setPosition(sf::Vector2f(20, 200));
	text.setCharacterSize(30);

	text2.setFont(font);
	text2.setFillColor(sf::Color::White);
	text2.setString("Version 1.0      Made by Victor Berzin");
	text2.setPosition(sf::Vector2f(320, 570));
	text2.setCharacterSize(13);

}


void AboutWindow::show(sf::RenderWindow *win ,sf::Sprite &background) {
	sf::Event event;
	while (win->isOpen()) {
		while (win->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win->close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter) {
					Menu menu;
					win->close();
					menu.show();
				}
			}
		}

		win->clear();
		win->draw(background);
		win->draw(text);
		win->draw(text2);
		win->display();
	}
}