//GameOverMessage.h

#pragma once
#include "SFML/Graphics.hpp"

class GameOverMessage
{
private:
	
	sf::Text text;
	sf::Font font;

	std::vector<sf::Text> textMenu;

public:
	GameOverMessage();
	void show(sf::RenderWindow *win, sf::Sprite &background, bool newRecord);
};

