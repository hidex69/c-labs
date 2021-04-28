// AboutWindow.cpp

#pragma once
#include "Menu.h"

class AboutWindow
{
private:
	std::string str;

	sf::Font font;
	sf::Text text, text2;
public:
	AboutWindow();
	void show(sf::RenderWindow *win, sf::Sprite &background);
};