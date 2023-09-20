#pragma once
#include "common.h"

class Menu {
public:
	Menu() {
		font.loadFromFile("font/waltographUI.ttf");
		text.setFont(font);
		position = 0;
	}
	void ShowMenu(sf::RenderWindow& window);
	int Option(int &option, sf::RenderWindow& window);
	int ShowManual(int& option, sf::RenderWindow& window);

	sf::Font font;
	sf::Text text;

	int xMouse;
	int yMouse;
	int position;
};