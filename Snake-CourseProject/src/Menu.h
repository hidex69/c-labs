//Menu.h

#pragma once
#include "SFML/Graphics.hpp"
#include "AboutWindow.h"
#include <vector>
#include <Windows.h>
#include "Game.h"

class Menu
{
private:
	sf::RenderWindow* win;
	sf::Text text;
	sf::Font font;

	sf::Texture texture;
	sf::Sprite background;

	std::vector<sf::Text> menuText;

	int selected;
public:
	Menu();

	sf::RenderWindow* getWindow();
	void selectedItem();
	void show();
	void draw();
};

